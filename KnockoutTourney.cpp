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
 
class KnockoutTourney {
	public:
	int meetRival(int N, int you, int rival) {
		int res = 0;
    int dist = abs(you - rival);
    while (you != rival) {
      you = (you + 1) / 2;
      rival = (rival + 1) / 2;
      res++;
    }

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, meetRival(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 16; int Arg1 = 8; int Arg2 = 9; int Arg3 = 4; verify_case(1, Arg3, meetRival(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 20; int Arg2 = 31; int Arg3 = 4; verify_case(2, Arg3, meetRival(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 65536; int Arg1 = 1000; int Arg2 = 35000; int Arg3 = 16; verify_case(3, Arg3, meetRival(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 60000; int Arg1 = 101; int Arg2 = 891; int Arg3 = 10; verify_case(4, Arg3, meetRival(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	KnockoutTourney ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
