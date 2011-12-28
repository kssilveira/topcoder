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

class StringFragmentation {
	public:
	int largestFontSize(string text, int width, int height) {
		int res = -1;

		vector <string> s;
		int pos = 0, npos;
		while((npos = text.find(' ', pos)) != -1) {
			s.push_back(text.substr(pos, npos - pos));
			pos = npos + 1;
		}
		
		int n = s.size();
		//rep(i, n) {
			//cout << "|" << s[i] << "|" << endl;
		//}

		repb(font, 8, 1000) {
			int cur = 0,
					ht = 0;
			while(cur < n && ht <= height) {
				int sz = -(font + 2) + (s[cur].size() + 1) * (font + 2);
				if(sz > width) {
					ht = height + 1;
					break;
				}
				while(cur < n && sz + (s[cur].size() + 1) * (font + 2) <= width) cur++;
				ht += 2 * font;
			}
			if(ht <= height) {
				res = font;
			}
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 40; int Arg3 = 9; verify_case(0, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 60; int Arg3 = 10; verify_case(1, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 10000; int Arg3 = 28; verify_case(2, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 10000; int Arg2 = 10000; int Arg3 = 1250; verify_case(3, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 50; int Arg2 = 50; int Arg3 = -1; verify_case(4, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "A"; int Arg1 = 9; int Arg2 = 14; int Arg3 = -1; verify_case(5, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	StringFragmentation ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
