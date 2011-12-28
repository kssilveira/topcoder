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
 
#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)
 
using namespace std;
 
class NetworkXZeroOne {
	public:
	string reconstruct(string message) {
		string res = message;
    int n = (int) res.size();

    int odd = 0;

    rep(i, n) {
      if (res[i] != '?') {
        odd = i % 2;
        if (res[i] != 'x') {
          odd = 1 - odd;
        }
        break;
      }
    }

    char val[] = "xo";

    rep(i, n) {
      // cout << i << " " << res[i] << endl;
      res[i] = val[(i + odd) % 2];
      // cout << i << " " << res[i] << endl;
    }
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "x?x?"; string Arg1 = "xoxo"; verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "?xo?"; string Arg1 = "oxox"; verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "xo"; string Arg1 = "xo"; verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "o??x??o"; string Arg1 = "oxoxoxo"; verify_case(3, Arg1, reconstruct(Arg0)); }
	void test_case_4() { string Arg0 = "???????x"; string Arg1 = "oxoxoxox"; verify_case(4, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	NetworkXZeroOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
