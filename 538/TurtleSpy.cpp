#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)
 
#define s(v) ((int) v.size())
 
using namespace std;

typedef long double ld;

const ld PI = 4 * atan(1);

ld to_rad(int x) {
  return x * PI / 180;
}

ld sqr(ld x) {
  return x * x;
}
 
class TurtleSpy {
	public:
	double maxDistance(vector <string> com) {
		ld res = 0;

    //cout << "PI: " << PI << endl;

    int n = s(com);
    int forward = 0, backward = 0;
    vector<int> ang;
    ri {
      char name[100];
      int v;
      sscanf(com[i].c_str(), "%s %d", name, &v);
      char c = name[0];
      if (c == 'f') {
        forward += v;
      }
      if (c == 'b') {
        backward += v;
      }
      if (c == 'r') {
        ang.push_back(v);
      }
      if (c == 'l') {
        ang.push_back(360 - v);
      }
    }

    bool can[360] = {0};
    bool next[360] = {0};
    can[0] = true;

    r(i, s(ang)) {
      memcpy(next, can, sizeof(can));
      r(j, 360) {
        if (next[j]) {
          can[(j + ang[i]) % 360] = true;
        }
      }
    }

    int best = 1000, choice = 0;
    r(i, 360) {
      if (!can[i]) continue;
      if (abs(i - 180) < best) {
        best = abs(i - 180);
        choice = i;
      }
    }
    ld endy = forward,
           endx = 0;
    //cout << "choice: " << choice << endl;
    int dir = (choice + 180) % 360;
    //cout << "dir: " << dir << endl;
    //if (dir >= 270 || dir <= 90) {
    if (1) {
      //cout << "endx: " << endx << " endy " << endy << endl;
      ld x = backward;
      endy += x * cos(to_rad(dir));
      endx += - x * sin(to_rad(dir));
    }

    //cout << "endx: " << endx << " endy " << endy << endl;

    res = sqrt(sqr(endx) + sqr(endy));

    /*
    printf("forward: %d, backward: %d", forward, backward);
    r(i, 360) {
      if (can[i]) {
        printf("%d ", i);
      }
    }
    cout << endl;//*/
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"forward 100", "backward 100", "left 90" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 141.4213562373095; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 200.0; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 40.58520737741619; verify_case(2, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	TurtleSpy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
