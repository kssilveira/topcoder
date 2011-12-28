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

bool found[50] = {0};
long double pd[50];
 
class TheBoredomDivOne {
	public:
	double find(int n, int m) {
		long double res = f(n, n + m);
		memset(found, 0, sizeof(found));
		return res;
	}
	long double f(int nn, int tt) {
		long double n = nn,
					 m = tt - nn,
					 t = tt,
					 den = t * (t - 1),
					 a1 = n * (n - 1),
					 a2 = m * n,
					 a3 = m * (m - 1);
		if(found[nn]) {
			return pd[nn];
		} else if(nn == tt) {
			return 0;
		}

		long double res;
		res = 2 * a2 * (f(nn + 1, tt) + 1) + a1;

		if(nn != tt - 1) {
			res += a3 * (f(nn + 2, tt) + 1);
		}
		
		res /= den * (1 - a1 / den);

		pd[nn] = res;
		found[nn] = true;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 1.5; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 2.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; double Arg2 = 13.831068977298521; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	TheBoredomDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
