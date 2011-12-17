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

int f[100010];

class RecurrenceRelation {
	public:
	int moduloTen(vector <int> coefficients, vector <int> initial, int N) {
		int n = coefficients.size();

		rep(i, n) {
			coefficients[i] = (coefficients[i] + 10000) % 10;
			initial[i] = (initial[i] + 10000) % 10;
			f[i] = initial[i];
		}
		
		if(N < n) {
			return initial[N];
		}

		repbe(i, n, N) {
			f[i] = 0;
			rep(k, n) {
				f[i] += (coefficients[k] * f[i - (n - k)]) % 10;
				f[i] %= 10;
			}
		}

		return f[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 5; verify_case(0, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 4; verify_case(1, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 6; verify_case(2, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; int Arg3 = 6; verify_case(3, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {25,143}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100000; int Arg3 = 0; verify_case(4, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {9,8,7,6,5,4,3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 654; int Arg3 = 5; verify_case(5, Arg3, moduloTen(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {901,492,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-6,-15,-39}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 4; verify_case(6, Arg3, moduloTen(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RecurrenceRelation ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
