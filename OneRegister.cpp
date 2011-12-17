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
int s;

bool rec(int t, string &r) {
	printf("rec(%i)\n", t);
	if(t == s) {
		r = "";
		return true;
	}
	if(t == 1) {
		r = "/";
		return true;
	}
	int sqr = sqrt(t);
	if(sqr * sqr == t) {
		string tmp;
		if(rec(sqr, tmp)) {
			r = tmp;
			r += "*";
			return true;
		}
	}
	sqr = t / 2;
	if(sqr + sqr == t) {
		string tmp;
		if(rec(sqr, tmp)) {
			r = tmp;
			r += "+";
			return true;
		}
	}
	return false;
}


 
class OneRegister {
	public:
	string getProgram(int ss, int t) {
		string res;
		s = ss;

		if(!rec(t, res)) {
			res = ":-(";
		}
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 392; string Arg2 = "+*+"; verify_case(0, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 256; string Arg2 = "/+***"; verify_case(1, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 256; string Arg2 = "**"; verify_case(2, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; string Arg2 = ""; verify_case(3, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; int Arg1 = 9; string Arg2 = ":-("; verify_case(4, Arg2, getProgram(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "/"; verify_case(5, Arg2, getProgram(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	OneRegister ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
