#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) reptbc(int, i, b, n, c)
#define reps(i, n) repbs(i, 0, n)
#define repbs(i, b, n) reptbc(unsigned int, i, b, n.size(), <)
#define reptbc(t, i, b, n, c) for(t i = b; i c n; i++)

using namespace std;

class ColorfulStrings {
	public:
	string getKth(int n, int k) {
		string res;

		

		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "238"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2000; string Arg2 = ""; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "23457"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 22; string Arg2 = "52"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 464; string Arg2 = "257936"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulStrings __test;
	__test.run_test(-1);
	system("pause");
}
// END CUT HERE
