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

int n;
static bitset<(int)(1e20)> gone, memo;

bool solve(int mask) {
  mask = mask & ~(1 << (n - 1));

  if (mask == 0) {
    return 0;
  }

  if (gone[mask]) return memo[mask];
  gone[mask] = 1;

  ri {
    if (mask & (1 << i)) {
      int next = mask & ~(1 << i);
      if (!(mask & (1 << (i + 1)))) {
        next = next | (1 << (i + 1));
        if (!solve(next)) {
          return memo[mask] = 1;
        }
      } else if (i + 3 < n &&
          (mask & (1 << (i + 2))) &&
          (!(mask & (1 << (i + 3))))) {
        next = next | (1 << (i + 3));
        if (!solve(next)) {
          return memo[mask] = 1;
        }
      }
    }
  }
  return memo[mask] = 0;
}
 
class EllysCheckers {
	public:
	string getWinner(string board) {
    gone.reset();
		string res;

    int mask = 0;
    n = s(board);
    ri {
      if (board[i] == 'o') {
        mask = (mask | (1 << i));
      }
    }

    res = solve(mask) ? "YES" : "NO";
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".o..."; string Arg1 = "YES"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "..o..o"; string Arg1 = "YES"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = ".o...ooo..oo.."; string Arg1 = "NO"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "......o.ooo.o......"; string Arg1 = "YES"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = ".o..o...o....o.....o"; string Arg1 = "NO"; verify_case(4, Arg1, getWinner(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	EllysCheckers ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
