#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MagicFingerprint {
	public:
	int countLuckyNumbers(int A, int B) {
		int res;

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 1; verify_case(0, Arg2, countLuckyNumbers(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 6; verify_case(1, Arg2, countLuckyNumbers(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1198; int Arg1 = 1198; int Arg2 = 1; verify_case(2, Arg2, countLuckyNumbers(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1223; int Arg1 = 1299; int Arg2 = 0; verify_case(3, Arg2, countLuckyNumbers(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 999999930; int Arg1 = 1000000000; int Arg2 = 2; verify_case(4, Arg2, countLuckyNumbers(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 1000000000; int Arg2 = 159720; verify_case(5, Arg2, countLuckyNumbers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	MagicFingerprint ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 