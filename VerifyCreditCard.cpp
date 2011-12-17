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

#define SIZE 51
 
class VerifyCreditCard {
	public:
	string checkDigits(string cardNumber) {
		string res;
		int num[SIZE];
		int n = (int) cardNumber.size();
		rep(i, n) {
			num[i] = cardNumber[i] - '0';
		}

		for(int i = n % 2; i < n; i += 2)
			num[i] *= 2;
 
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += num[i] % 10 + num[i] / 10;
		}
 
		if(sum % 10 == 0) {
			res = "VALID";
		} else {
			res = "INVALID";
		}
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "21378"; string Arg1 = "VALID"; verify_case(0, Arg1, checkDigits(Arg0)); }
	void test_case_1() { string Arg0 = "31378"; string Arg1 = "INVALID"; verify_case(1, Arg1, checkDigits(Arg0)); }
	void test_case_2() { string Arg0 = "11111101"; string Arg1 = "VALID"; verify_case(2, Arg1, checkDigits(Arg0)); }
	void test_case_3() { string Arg0 = "50005"; string Arg1 = "VALID"; verify_case(3, Arg1, checkDigits(Arg0)); }
	void test_case_4() { string Arg0 = "542987223412"; string Arg1 = "INVALID"; verify_case(4, Arg1, checkDigits(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	VerifyCreditCard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
