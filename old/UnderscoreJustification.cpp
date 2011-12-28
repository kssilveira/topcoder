#include <algorithm>
#include <ctype.h>
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
 
class UnderscoreJustification {
	public:
	string justifyLine(vector <string> words, int width) {
		string res;
		int n = (int) words.size();

		int total = 0;
		rep(i, n) {
			total += (int) words[i].size();
		}
 
		int spaces = width - total;
		int extra = spaces % (n - 1);
		int quo = spaces / (n - 1);

			rep(i, n - 1) {
				res += words[i];
				rep(j, quo)
					res += "_";
				if((extra && !isupper(words[i + 1][0])) ||
						i + 1 == n - extra) {
					extra--;
					res += "_";
				}
			}
			res += words[n - 1];
			return res;

 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "A___quick__brown__fox__jumps__over__the__lazy__dog"; verify_case(0, Arg2, justifyLine(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; string Arg2 = "Alpha_Beta_Gamma__Delta__Epsilon"; verify_case(1, Arg2, justifyLine(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"Hello", "world", "John", "said"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; string Arg2 = "Hello____world___John____said"; verify_case(2, Arg2, justifyLine(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	UnderscoreJustification ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
