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

class TheEquation {
	public:
	int leastSum(int X, int Y, int P) {
		int res = 0;

		rep(res, 2 * P + 1) {
			repb(a, 1, res) {
				if((a * X + (res - a) * Y) % P == 0) {
					return res;
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
	void test_case_0() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 5; int Arg3 = 3; verify_case(0, Arg3, leastSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 2; verify_case(1, Arg3, leastSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 998; int Arg1 = 999; int Arg2 = 1000; int Arg3 = 501; verify_case(2, Arg3, leastSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1000; int Arg3 = 1000; verify_case(3, Arg3, leastSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 347; int Arg1 = 873; int Arg2 = 1000; int Arg3 = 34; verify_case(4, Arg3, leastSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TheEquation ___test; 
	___test.leastSum(1000, 1000, 1000);
	___test.run_test(-1); 
} 
// END CUT HERE 
