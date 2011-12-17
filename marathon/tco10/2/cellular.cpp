#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <cstring>

typedef int Time;
inline Time getTime(){
	timeval tv; 
	gettimeofday(&tv, 0); 
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

#define	rep(i, n) rept(int, i, n)
#define repb(i, b, n) reptb(int, i, b, n)
#define repu(i, n) rept(unsigned int, i, n)
#define rept(t, i, n) reptb(t, i, 0, n)
#define reptb(t, i, b, n) for(t i = b; i < n; i++)

#define MAX_TIME 9800
//#define MAX_TIME 19800
#define COEF 4
#define MAX_N 630
#define MAX_K 20
#define MAX_TRIES 50
#define RAND_SEARCH_COEF 1
#define MOD_COEF 50

using namespace std;

typedef bool Board[102][102];
Board board;
Board t[MAX_K + 1];
Board res;
//Board &curboard = t[0];
#define curboard t[0]
int best;

#define INDEX(i, j) i][j
#define ATTRIB(l, r) memcpy(l, r, sizeof(l))

class CellularAutomaton
{
public:
	int R, C, K;
	int cx, cy, dist, cxm, cym;
	string rules;
	inline vector <string> configure(vector <string> grid, string rules, int N, int K) {
		Time tbegin = getTime();

		srand((unsigned) 0xDEADBEEF);

		R = grid.size(), C = grid[0].size();
		this->K = K;
		this->rules = rules;
		cx = R / 2;
		cy = C / 2;
		cxm = !(R % 2);
		cym = !(C % 2);

		//cerr << "cx: " << cx << " cy: " << cy << " cxm: " << cxm << " cym: " << cym << endl;

		rep(i, R) {
			rep(j, C) {
				board[INDEX(i + 1, j + 1)] = grid[i][j] - '0';
			}
		}

		//print(board);

		ATTRIB(curboard, board);
		best = eval();
		ATTRIB(res, curboard);

		cerr << "First: " << best << endl;

		Time tlast = getTime();
		int iter = 0;
		int sqrt;
		for(sqrt = 0; sqrt * sqrt <= N; sqrt++);
		dist = (sqrt - 1) / 2;
		int modx = 2, mody = 1, bi = 0, bj = 0, mrc = max(R, C), mod = MOD_COEF * dist;
		while(1) {
			if(!iter || (!(iter % mod) && dist < mrc)) {
				dist++;
				//dist = 2;
				//dist = mrc;
				modx = min(2 * dist - cxm + 1, R),
				mody = min(2 * dist - cym + 1, C);
				bi = max(cx - dist, 0);
				bj = max(cy - dist, 0);
				mod += MOD_COEF;

				//cerr << "dist: " << dist << " modx: " << modx << " mody: " << mody << " nval: " << nval << " bi: " << bi << " bj: " << bj << endl;
			}

			iter++;
			
			rep(nn, N) {
				int i = rand() % modx,
						j = rand() % mody;
				curboard[INDEX(i + 1 + bi, j + 1 + bj)] = !curboard[INDEX(i + 1 + bi, j + 1 + bj)];
			}
			
			//cerr << "diff:" << endl;
			//rep(i, R) {
				//rep(j, C)
					//cerr << (curboard[i + 1][j + 1] ^ board[i + 1][j + 1]);
				//cerr << endl;
			//}

			int temp = eval();
			if(temp > best) {
				best = temp;
				ATTRIB(res, curboard);
				//cerr << "Best: " << best << endl;
				//cerr << "Iter: " << iter << endl;
				//print(res);
			}

			if((iter % 100) == 0) {
				Time tcur = getTime();
				if(tcur - tbegin + tcur - tlast >= MAX_TIME * RAND_SEARCH_COEF) {
					break;
				}
				tlast = tcur;
			}

			ATTRIB(curboard, board);
		}

		cerr << "Best: " << best << endl;
		cerr << "Iter: " << iter << endl;
		cerr << "(" << bi << ", " << bj << ")" << endl;

		/*
		// busca local
		int changes[MAX_N][2];
		tlast = getTime();
		iter = 0;
		int nchanges = 0;
		bool changed = true;
		ATTRIB(curboard, board);
		while(1) {
			iter++;
			//int n = N;

			if(changed) {
				changed = false;
				nchanges = 0;
				rep(i, R)
					rep(j, C)
						if(res[INDEX(i + 1, j + 1)] != board[INDEX(i + 1, j + 1)]) {
							changes[nchanges][0] = i + 1;
							changes[nchanges][1] = j + 1;
							nchanges++;
						}
				//cerr << "nchanges: " << nchanges << endl;
				//rep(i, nchanges) {
					//cerr << changes[i][0] << " " << changes[i][1] << endl;
				//}
			}
				
			//rep(nn, n) {
				int i = rand() % R,
						j = rand() % C,
						k = rand() % nchanges;
				curboard[INDEX(changes[k][0], changes[k][1])] 
				 = board[INDEX(changes[k][0], changes[k][1])];
				curboard[INDEX(i + 1, j + 1)] = !board[INDEX(i + 1, j + 1)];
			//}
			
			int temp = eval();
			if(temp > best) {
				best = temp;
				ATTRIB(res, curboard);
				changed = true;
				cerr << "Best: " << best << endl;
				cerr << "Iter: " << iter << endl;
				print(res);
			}

			if((iter % 100) == 0) {
				Time tcur = getTime();
				if(tcur - tbegin + tcur - tlast >= MAX_TIME) {
					break;
				}
				tlast = tcur;
			}

			ATTRIB(curboard, board);
		}

		cerr << "Best: " << best << endl;
		cerr << "Iter: " << iter << endl;
		//*/

		rep(i, R) {
			rep(j, C) {
				grid[i][j] = res[INDEX(i + 1, j + 1)] + '0';
			}
		}

		return grid;
	}

	inline int eval() {
		//int cur = 0;
		int res = 0;

		//ATTRIB(t[cur], curboard);

		int bi = max(cx - (dist), 0),
				ei = min(cx + (dist) - cxm + 1, R),
				bj = max(cy - (dist), 0),
				ej = min(cy + (dist) - cym + 1, C);
		
		rep(cur, K) {
			bi--;
			if(bi < 0) bi = 0;
			bj--;
			if(bj < 0) bj = 0;
			ei++;
			if(ei > R) ei = R;
			ej++;
			if(ej > C) ej = C;

			rep(j, C && bi == 0) {
				t[cur][INDEX(0    , j + 1)] = t[cur][INDEX(R, j + 1)];
				t[cur][INDEX(R + 1, j + 1)] = t[cur][INDEX(1, j + 1)];
			}

			rep(i, R && bj == 0) {
				t[cur][INDEX(i + 1, 0    )] = t[cur][INDEX(i + 1, C)];
				t[cur][INDEX(i + 1, C + 1)] = t[cur][INDEX(i + 1, 1)];
			}

			t[cur][INDEX(0, 0)] = t[cur][INDEX(R, C)];
			t[cur][INDEX(R + 1, C + 1)] = t[cur][INDEX(1, 1)];
			t[cur][INDEX(0, C + 1)] = t[cur][INDEX(R, 1)];
			t[cur][INDEX(R + 1, 0)] = t[cur][INDEX(1, C)];

			repb(i, bi, ei) {
				repb(j, bj, ej) {
					int count = t[cur][INDEX(i    , j    )] +
											t[cur][INDEX(i + 1, j    )] +
											t[cur][INDEX(i + 2, j    )] +
											t[cur][INDEX(i    , j + 1)] +
											t[cur][INDEX(i + 2, j + 1)] + 
											t[cur][INDEX(i    , j + 2)] + 
											t[cur][INDEX(i + 1, j + 2)] +
											t[cur][INDEX(i + 2, j + 2)];
					switch(rules[count]) {
						case '=':
							t[cur + 1][INDEX(i + 1, j + 1)] = t[cur][INDEX(i + 1, j + 1)];
							break;
						case '-':
							t[cur + 1][INDEX(i + 1, j + 1)] = 0;
							break;
						case '+':
							t[cur + 1][INDEX(i + 1, j + 1)] = 1;
							break;
						case 'X':
							t[cur + 1][INDEX(i + 1, j + 1)] = !t[cur][INDEX(i + 1, j + 1)];
							break;
					}
					//res += t[cur + 1][INDEX(i + 1, j + 1)];
				}
			}

			//if(res <= best / COEF) {
				//cerr << '.';
				//return res;
			//}
		}

		res = 0;
		rep(i, R)
			rep(j, C)
				res += t[K][INDEX(i + 1, j + 1)];

		return res;
	}

	inline void print(Board b) {
		rep(i, R + 2) {
			rep(j, C + 2) {
				cerr << (char)('0' + (b[INDEX(i, j)] ^ board[INDEX(i, j)]));
			}
			cerr << endl;
		}
		cerr << endl;
		cerr << flush;
	}
};

#if MAIN
	#if JAVA
		int main()
		{
			CellularAutomaton t;
			int R, N, K;
			string rules;
			vector <string> grid(100);

			cin >> R;
			//cerr << R << endl;

			rep(i, R) {
				cin >> grid[i];
				//cerr << grid[i] << endl;
			}
			grid.resize(R);

			cin >> rules >> N >> K;
			//cerr << rules << endl << N << endl << K << endl;

			vector <string> res = t.configure(grid, rules, N, K);
			repu(i, res.size()) {
				cout << res[i] << endl;
			}
			cout << flush;
			return 0;
		}
	#else
		int main()
		{
			CellularAutomaton t;
			int R = 6, C = 5, N = 9, K = 2;
			const char *rules = "--=+-----";
			vector <string> grid(R);
			rep(i, R) {
				rep(j, C) {
					grid[i] += '0' + (i == j || j == 1);
				}
			}
			vector <string> res = t.configure(grid, rules, N, K);
			repu(i, res.size()) {
				cout << res[i] << endl;
			}
			/*
			bitset<8> b;
			b[7] = 1;
			cout << endl;
			rep(i, 10) {
				cout << i << ": ";
				cout << (b >> i) << endl;
			}
			cout << endl;
			//*/
			return 0;
		}
	#endif
#endif

