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
 
class DucksAlignment {
	public:
	int minimumTime(vector <string> Grid) {
		int res = INT_MAX;
    int n = s(Grid), m = s(Grid[0]);
    char grid[100][100];
    ri {
      rjm {
        grid[i][j] = Grid[i][j];
      }
    }

r(T, 2) {
  vector<pair<int, int> > pos;
    ri {
      rjm {
        if (grid[i][j] == 'o') {
          pos.push_back(make_pair(j, i));
        }
      }
    }
    int total = s(pos);
    //cout << "total: " << total << endl;
    //ppn(total);
    sort(pos.begin(), pos.end());

    //r(i, total) {
      //cout << pos[i].first << ' ' << pos[i].second << endl;
    //}

    ri {
      for (int j = 0; j + total <= n; j++) {
        int cur = 0;
        r(k, total) {
          cur += abs(pos[k].second- i) +
            abs(pos[k].first - (j + k));
        }
        res = min(res, cur);
      }
    }

    char tab[100][100];
    ri {
      rjm {
        tab[i][j] = grid[i][j];
      }
    }

    swap(n, m);

    ri {
      rjm {
        grid[i][j] = tab[j][i];
      }
    }
}

 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o",
 "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
	void test_case_1() { string Arr0[] = {".o...",
 "..o..",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".........",
 "....o....",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	DucksAlignment ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
