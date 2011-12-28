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

bool valid(char c)
{
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= '0' && c <= '9') return true;
	return c == '.';
}

class UnLinker {
	public:
	string clean(string text) {
		string res;

		char prefix[][10] = {"http://", "http://www.", "www."},
				 sufix[][10] = {".com", ".org", ".edu", ".info", ".tv"};
		
		int n = res.size();

		rep(p, 3) {
			rep(i, n) {
				bool wrong = false;
				int j = 0;
				while(prefix[p][j]) {
					if(text[i + j] != prefix[p][j]) {
						wrong = true;
						break;
					}
					j++;
				}
				if(wrong) {
					continue;
				}
				int end = i + j + 1;
				while(end < n && valid[text[end]]) {
					end++;
				}
				if(end < n) {
					end--;
				}
				rep(s, 5) {
					int k = strlen(sufix[s] - 1);
					while(k >= 0) {
						// I'm tired of this!


				}
			}
		}

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "espihttp://www.tv.org.superwww.cali.comaladocious"; string Arg1 = "espiOMIT1aladocious"; verify_case(0, Arg1, clean(Arg0)); }
	void test_case_1() { string Arg0 = "check www.foo.com 4 www.foo.com www.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2 OMIT3"; verify_case(1, Arg1, clean(Arg0)); }
	void test_case_2() { string Arg0 = "check www.foo.com 4 www.foo.comwww.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2"; verify_case(2, Arg1, clean(Arg0)); }
	void test_case_3() { string Arg0 = "check www.foo.com 4 www.foo.comhttp://scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2OMIT3"; verify_case(3, Arg1, clean(Arg0)); }
	void test_case_4() { string Arg0 = "http://411.com goodz 4 www.733t.com, 2http://..com"; string Arg1 = "OMIT1 goodz 4 OMIT2, 2OMIT3"; verify_case(4, Arg1, clean(Arg0)); }
	void test_case_5() { string Arg0 = "http.//say.org,www.jeeves.x.info,www.comhttp://.tv"; string Arg1 = "http.//say.org,OMIT1,www.comhttp://.tv"; verify_case(5, Arg1, clean(Arg0)); }
	void test_case_6() { string Arg0 = "http://www.www.com/www"; string Arg1 = "OMIT1/www"; verify_case(6, Arg1, clean(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	UnLinker ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
