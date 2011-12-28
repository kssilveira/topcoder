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

bool isVog(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
		c == 'u';
}
 
class TxMsg {
	public:
	string getMessage(string original) {
		string res;
		int n = (int) original.size();

		string cur = "";
		rep(i, n + 1) {
			if(i == n || original[i] == ' ') {
				//cout << "c: " << cur << endl;
				int m = cur.size();
				bool found = false;
				rep(j, m) {
					if(!isVog(cur[j])) {
						found = true;
						break;
					}
				}
				if(!found) {
					res += cur;
				} else {
					rep(j, m) {
						if(!isVog(cur[j])) {
							res += cur[j];
							j++;
							while(j < m && !isVog(cur[j])) {
								j++;
							}
							j--;
						}
					}
				}
				if(i != n)
				res += ' ';
				cur = "";
			} else {
				cur += original[i];
			}
		}
		res += cur;
				

 
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "text message"; string Arg1 = "tx msg"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "ps i love u"; string Arg1 = "p i lv u"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "please please me"; string Arg1 = "ps ps m"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = "back to the ussr"; string Arg1 = "bc t t s"; verify_case(3, Arg1, getMessage(Arg0)); }
	void test_case_4() { string Arg0 = "aeiou bcdfghjklmnpqrstvwxyz"; string Arg1 = "aeiou b"; verify_case(4, Arg1, getMessage(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	TxMsg ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
