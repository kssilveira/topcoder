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
 
class RemovingDigits {
	public:
	string maxNumber(string number, string digits) {
		string res;

		int n = (int) number.size(),
				m = (int) digits.size();

		sort(digits.begin(), digits.end());

		for(int i = 0; i < m; i++) {
			bool found = false;
			for(int j = 0; j < (int) number.size() - 1; j++) {
				if(number[j] == digits[i] && number[j] < number[j + 1]) {
					number.erase(j, 1);
					found = true;
					break;
				}
			}
			if(!found) {
				for(int j = (int) number.size() - 1; j >= 0; j--) {
					if(number[j] == digits[i]) {
						number.erase(j, 1);
						break;
					}
				}
			}
		}

		return number;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12345"; string Arg1 = "513"; string Arg2 = "24"; verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "112352"; string Arg1 = "1123"; string Arg2 = "52"; verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "123456654321"; string Arg1 = "612534"; string Arg2 = "654321"; verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "654321123456"; string Arg1 = "612534"; string Arg2 = "654321"; verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "2654982765982365"; string Arg1 = "2345978"; string Arg2 = "698265265"; verify_case(4, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RemovingDigits ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
