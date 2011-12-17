import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.security.*;
import javax.swing.*;
import java.util.Random;

// ------------- class Point -----------------------------
class P {
    public int x,y;
    public P() {};
    public P(int x1, int y1)
    {   x=x1;    y=y1;    }
}

// ------------- class G2D -------------------------------
class G2D {
    public static P substr(P p1, P p2) {
	return new P(p1.x-p2.x, p1.y-p2.y);
    }
    public static double norm(P p) {
	return Math.sqrt(p.x*p.x + p.y*p.y);
    }
    public static int dot(P p1, P p2) {
	return p1.x*p2.x+p1.y*p2.y;
    }
    public static double dist(P p1, P p2) {
        return norm(substr(p1, p2));
    }
}

// ------------- class Edge ------------------------------
class Edge {
    public P p1,p2,vect;	//vector p1 -> p2
    public double norm;
    public Edge() {};
    public Edge(P p1n, P p2n) {
        p1 = p1n;
        p2 = p2n;
        vect = G2D.substr(p2, p1);
        norm = G2D.norm(vect);
    }
    public Edge(int x1, int y1, int x2, int y2) {
        p1 = new P(x1,y1);
        p2 = new P(x2,y2);
        vect = G2D.substr(p2, p1);
        norm = G2D.norm(vect);
    }
    boolean eq(double a, double b){
      return Math.abs(a-b) < 1e-9;
    }
    // ---------------------------------------------------
    public boolean intersect(Edge other) {
        //do edges "this" and "other" intersect?
        if (Math.min(p1.x,p2.x)>Math.max(other.p1.x,other.p2.x)) return false;
        if (Math.max(p1.x,p2.x)<Math.min(other.p1.x,other.p2.x)) return false;
        if (Math.min(p1.y,p2.y)>Math.max(other.p1.y,other.p2.y)) return false;
        if (Math.max(p1.y,p2.y)<Math.min(other.p1.y,other.p2.y)) return false;

        int den = other.vect.y*vect.x-other.vect.x*vect.y;
        int num1 = other.vect.x*(p1.y-other.p1.y)-other.vect.y*(p1.x-other.p1.x);
        int num2 =       vect.x*(p1.y-other.p1.y)-      vect.y*(p1.x-other.p1.x);

        //parallel edges
        if (den==0)
        {   if (Math.min(other.dist2(this),dist2(other)) > 0)
                return false;
            //on the same line - "not intersect" only if one of the vertices is common,
            //and the other doesn't belong to the line
            if ((this.p1==other.p1 && eq(G2D.dist(this.p2, other.p2) , this.norm + other.norm)) || 
                (this.p1==other.p2 && eq(G2D.dist(this.p2, other.p1) , this.norm + other.norm)) ||
                (this.p2==other.p1 && eq(G2D.dist(this.p1, other.p2) , this.norm + other.norm)) ||
                (this.p2==other.p2 && eq(G2D.dist(this.p1, other.p1) , this.norm + other.norm)))
                return false;
            return true;
        }

        //common vertices
        if (this.p1==other.p1 || this.p1==other.p2 || this.p2==other.p1 || this.p2==other.p2)
            return false;

        double u1 = num1*1./den;
        double u2 = num2*1./den;
        if (u1<0 || u1>1 || u2<0 || u2>1)
            return false;
        return true;
    }
    // ---------------------------------------------------
    public double dist(P p) {
        //distance from p to the edge
        if (G2D.dot(vect, G2D.substr(p, p1))<=0)
            return G2D.dist(p, p1);			//from p to p1
        if (G2D.dot(vect, G2D.substr(p, p2))>=0)
            return G2D.dist(p, p2);			//from p to p2
        //distance to the line itself
        return Math.abs(-vect.y*p.x+vect.x*p.y+p1.x*p2.y-p1.y*p2.x)/norm;
    }
    // ---------------------------------------------------
    public double dist2(Edge other) {
        //distance from the closest of the endpoints of "other" to "this"
        return Math.min(dist(other.p1), dist(other.p2));
    }
}

public class Planarity
{
	int V, E;
	int[] vx, vy, edges;
	final String seed = "1";
	final int SZ = 700;
	int minx, miny, maxx, maxy;
	public int[] untangle(int V, int[] edges) {
		long begin = System.currentTimeMillis(), curT, lastT = begin;
		this.edges = edges;
		this.V = V;
		this.E = edges.length / 2;
		int[] res = new int[2 * V];
		vx = new int[V];
		vy = new int[V];
		int best = calcScore();
		//SecureRandom r;
		Random r;
		minx = miny = SZ;
		maxx = maxy = -1;
		try {
			//r = SecureRandom.getInstance("SHA1PRNG");
			//r.setSeed(Long.parseLong(seed));
			r = new Random(Long.parseLong(seed));
			//V = r.nextInt(91)+10;
			for(int i = 0; i < V; i++) {
				boolean found;
				do {
					vx[i] = r.nextInt(SZ);
					vy[i] = r.nextInt(SZ);
					found = false;
					for(int j = 0; j < i; j++) {
						if(vx[i] == vx[j] && vy[i] == vy[j]) {
							found = true;
							break;
						}
					}
				} while(found);
				minx = Math.min(minx, vx[i]);
				miny = Math.min(miny, vy[i]);
				maxx = Math.max(maxx, vx[i]);
				maxy = Math.max(maxy, vy[i]);
			}
			for(int i = 0; ; i++) {
				if(i % 100 == 99) {
					curT = System.currentTimeMillis();
					if(curT + curT - lastT > 9800 + begin) break;
					lastT = curT;
				}
				int v = r.nextInt(V), lvx = vx[v], lvy = vy[v];
				boolean found;
				do {
					//vx[v] = r.nextInt(SZ);
					//vy[v] = r.nextInt(SZ);
					vx[v] = r.nextInt(maxx - minx + 1) + minx;
					vy[v] = r.nextInt(maxy - miny + 1) + miny;
					found = false;
					for(int j = 0; j < V; j++) {
						if(j != v && vx[v] == vx[j] && vy[v] == vy[j]) {
							found = true;
							break;
						}
					}
				} while(found);
				int cur = calcScore();
				if(false|| cur < best) {
					best = cur;
					minx = Math.min(minx, vx[v]);
					miny = Math.min(miny, vy[v]);
					maxx = Math.max(maxx, vx[v]);
					maxy = Math.max(maxy, vy[v]);
				} else {
					vx[v] = lvx;
					vy[v] = lvy;
				}
			}
		} catch (Exception e) {}
		for(int i = 0; i < V; i++) {
			res[2 * i] = vx[i];
			res[2 * i + 1] = vy[i];
		}
		return res;
	}
	public static void main(String args[]) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int V = Integer.parseInt(br.readLine());
			int N = Integer.parseInt(br.readLine());
			int[] edges = new int[N];
			for(int i = 0; i < N; i++)
				edges[i] = Integer.parseInt(br.readLine());
			int[] coords = new Planarity().untangle(V, edges);
			for(int i = 0; i < coords.length; i++) {
				System.out.println(coords[i]);
			}
		} catch (Exception e) {}
	}
    // ---------------------------------------------------
    int calcScore() {
        //calculate the score of current layout as the number of intersections between edges
        int i,j,nint=0;
        //we use the number of pairs of edges that intersect (don't care whether intersection points coincide)
        //intersection is having at least one common point, except for common vertice
        P[] vp = new P[V];
        Edge[] es = new Edge[E];
        for (i=0; i<V; i++)
            vp[i] = new P(vx[i], vy[i]);
        for (i=0; i<E; i++)
            es[i] = new Edge(vp[edges[2*i]], vp[edges[2*i+1]]);
        for (i=0; i<E; i++)
        for (j=0; j<i; j++)
            //check whether edges i and j intersect
            if (es[i].intersect(es[j]))
                nint++;
        return nint;
    }
}

