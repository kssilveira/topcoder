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

const int MAX = 500000;

bitset<MAX> iscomp;
 
class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
    rb(i, 2, N + 1) {
      if (!iscomp[i]) {
        rb(j, i + i, N + 1) {
          iscomp[j] = true;
        }
      }
    }
    
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	PrimeCompositeGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
