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

class EqualizeStrings {
	public:
	string other(string s, string t) {
		string res;

		int n = s.size();
		int cnt, a, b, best;
		repb(i, 0, n) {
			best = 100;
			char p;
			a = s[i] - 'a';
			b = t[i] - 'a';
			rep(j, 26) {
				cnt = 0;
				cnt += min(abs(a - j), abs(25 - a + j + 1)) +
					min(abs(b - j), abs(25 - b + j + 1));
				if(cnt < best) {
					best = cnt;
					p = 'a' + j;
				}
			}
			res += p;
		}
		return res;
	}

	string getEq(string s, string t) {
		string res;
		int n = s.size();
		int alpha = 'z' - 'a' + 1;

		rep(i, n) {
			s[i] -= 'a';
			t[i] -= 'a';
		}

		rep(i, n) {
			int d1 = abs(s[i] - t[i]);
			int d2 = (alpha - d1) % alpha;
			//printf("%i %i %i %i\n", d1, d2, s[i], t[i]);
			if(d1 < d2) {
				if(s[i] > t[i]) {
					swap(s[i], t[i]);
				}
				if(s[i] <= t[i]) {
					if(s[i] + d1 >= alpha) {
						res += 'a';
					} else {
						res += (min(s[i], t[i]) + 'a');
					}
				}
			} else if(d1 > d2) {
				if(s[i] < t[i]) {
					swap(s[i], t[i]);
				}
				if(s[i] >= t[i]) {
					if(s[i] + d2 >= alpha) {
						res += 'a';
					} else {
						res += (min(s[i], t[i]) + 'a');
					}
				}
				//res += (min(s[i], t[i]) + 'a');
			} else {
				//printf("%i %i %c %c\n", d1, d2, s[i] + 'a', t[i] + 'a');
				if(s[i] > t[i]) {
					swap(s[i], t[i]);
				}
				if(s[i] <= t[i]) {
					if(s[i] + d1 >= alpha) {
						res += 'a';
					} else if(t[i] + d2 >= alpha) {
						res += 'a';
					} else {
						res += (min(s[i], t[i]) + 'a');
					}
				}
				//res += (min(s[i], t[i]) + 'a');
			}
		}

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cat"; string Arg1 = "dog"; string Arg2 = "caa"; verify_case(0, Arg2, getEq(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "bcdefghijklmnopqrstuvwxyza"; string Arg2 = "abcdefghijklmnopqrstuvwxya"; verify_case(1, Arg2, getEq(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "programmingcompetitionsrule"; string Arg1 = "programmingcompetitionsrule"; string Arg2 = "programmingcompetitionsrule"; verify_case(2, Arg2, getEq(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoderopen"; string Arg1 = "onlinerounds"; string Arg2 = "onlcndaoondn"; verify_case(3, Arg2, getEq(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	EqualizeStrings ___test; 
	char s[2], t[2];
	s[1] = t[1] = 0;
	int found = 0;
	repbe(i, 'a', 'z') {
		s[0] = i;
		repbe(j, 'a', 'z') {
			t[0] = j;
			if(___test.getEq(s, t) != ___test.other(s, t)) {
				printf("%s\n%s\n---\n", s, t);
				found = 1;
				break;
			}
		}
		if(found) break;
	}
	___test.run_test(-1); 
} 
// END CUT HERE 
