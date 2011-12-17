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
 
class NumericalPerfectionLevel {
	public:
	int getLevel(long long N) {
		int res = 0;
 
		long long end = sqrt(N);
		while(!(N % 2) && N > 1) {
			N /= 2;
			res++;
		}
		printf("res: %i\n", res);
		for(long long i = 3; i <= end && N > 1; i += 2) {
			while(!(N % i) && N > 1) {
				printf("%lli ", i);
				N /= i;
				res++;
			}
		}
		if(N != 1) {
			res++;
		}
		printf("\n");
 
		printf("res: %i\n", res);
		int log = 0;
		int div = 4;
		
		while(div <= res) {
			log++;
			div *= div;
		}
 
		return log;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arg1 = 0; verify_case(0, Arg1, getLevel(Arg0)); }
	void test_case_1() { long long Arg0 = 144LL; int Arg1 = 1; verify_case(1, Arg1, getLevel(Arg0)); }
	void test_case_2() { long long Arg0 = 1152LL; int Arg1 = 1; verify_case(2, Arg1, getLevel(Arg0)); }
	void test_case_3() { long long Arg0 = 1679616LL; int Arg1 = 2; verify_case(3, Arg1, getLevel(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	NumericalPerfectionLevel ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
