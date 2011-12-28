#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cstring>
#include <climits>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

typedef bool Taken[30];
Taken taken;

string solve(string s, int keyPresses, int keyPressed)
{
	Res res;

	if(s.size() <= 1) {
		res.s = s;
		res.keyPresses = keyPresses;
		res.keyPressed = keyPressed;
		return res;
	}

	string next = s.substr(1, s.size() - 2);
	char first = s[0], last = s[s.size() - 1];

	if(first == last) {
		res = solve(next, keyPresses, keyPressed);
		res.s = cat(first, res.s, last);
		return res;
	}

	if(taken[first]) {
		Res tmp = solve(next, keyPresses, keyPressed + 1);
		tmp.s = cat(first, tmp.s, first);
		if(tmp < res)
			res = tmp;
	} else {
		taken[first] = true;
		Res tmp = solve(next, keyPresses + 1, keyPressed + 1);
		tmp.s = cat(first, tmp.s, first);
		if(tmp < res)
			res = tmp;
		taken[first] = false;
	}
	if(taken[last]) {
		Res tmp = solve(next, keyPresses, keyPressed + 1);
		tmp.s = cat(last, tmp.s, last);
		if(tmp < res)
			res = tmp;
	} else {
		taken[last] = true;
		Res tmp = solve(next, keyPresses + 1, keyPressed + 1);
		tmp.s = cat(last, tmp.s, last);
		taken[last] = false;
		if(tmp < res)
			res = tmp;
	}
}


class Palindromize3 {
	public:
		string getPalindrome(string s) {
			memset(taken, 0, sizeof(taken));
			return solve(s, 0, 0);
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arg0 = "aszsbsz"; string Arg1 = "zszszsz"; verify_case(0, Arg1, getPalindrome(Arg0)); }
		void test_case_1() { string Arg0 = "ababab"; string Arg1 = "aaaaaa"; verify_case(1, Arg1, getPalindrome(Arg0)); }
		void test_case_2() { string Arg0 = "topcoderopen"; string Arg1 = "nepooeeoopen"; verify_case(2, Arg1, getPalindrome(Arg0)); }
		void test_case_3() { string Arg0 = "dfiuwifuqwieubaoiewhroiahw"; string Arg1 = "wfiiwifueiieuueiieufiwiifw"; verify_case(3, Arg1, getPalindrome(Arg0)); }

		// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	Palindromize3 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
