#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

static int tab[51][500001];

class SuperSum {
	public:
	int calculate(int k, int n) {
		memset(tab, 0, 51 * 500001 * sizeof(int));
		return comb(n + k, k + 1);
	}
	
	int comb(int n, int m) {
		if(m == 0 || m == n) return 1;
		if(n < 51 && m < 500001) {
			if(tab[n][m]) return tab[n][m];
			return tab[n][m] = (comb(n - 1, m - 1) + comb(n - 1, m)) % 1000000007;
		}
		return (comb(n - 1, m - 1) + comb(n - 1, m)) % 1000000007;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 6; verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 2002; verify_case(2, Arg2, calculate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 35; int Arg2 = 150595840; verify_case(3, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	SuperSum ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
