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
 
class TheBoringStoreDivOne {
	public:
	string find(string j, string b) {
		string res;
		int n = (int) f.size(),
				m = (int) g.size();
 
		for(int i = 0; i < m; i++) {
			string sf;
			for(int j = 0; j + i < m; j++) {
				sf += f[i + j];
				for(int k = i + j + 1; k < m; k++) {
					string sg;
					for(int l = 0; l + k < m; l++) {
						sg += f[k + l];
						if(l <= j && f[k + l] != f[i + j]) break;
						string mid;
						if(l <= j) {
							for(int m = l + 1; m < j; m++) {
								mid += sf[m];
							}
						} else {
							for(int m = j + 1; m < l; m++) {
								mid += sf[m];
							}
						}
						for(int ii = 0; ii < m; ii++) {
							string sg

						
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "StoreOfJohn"; string Arg1 = "StoreOfBrus"; string Arg2 = "or"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JohnAndJohn"; string Arg1 = "John"; string Arg2 = ""; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "JohnLikesToPlayGames"; string Arg1 = "BrusAlsoLikesToPlayGames"; string Arg2 = "esToPlayGames"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; string Arg1 = "abacabadabacaba"; string Arg2 = "abaabacaba"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	TheBoringStoreDivOne ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
