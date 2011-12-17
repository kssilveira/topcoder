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

class TwoRegisters {
	public:
	char s[1000000];
	string result;
	int nmin;
	string minProg(int r) {
		string res;

		s[0] = 0;
		nmin = INT_MAX;
		solve(1, 1, r, 0);

		return result;
	}
	string other(int r) {
		string res;
		return res;
	}
	bool solve(int x, int y, int sum, int depth) {
		//printf("solve(%i, %i, %i, %i)\n", x, y, sum, depth);
		//printf("s: %s nmin: %i result: %s\n", s, nmin, result.c_str());
		if(x == sum) {
			s[depth] = 0;
			if(depth < nmin || (depth == nmin && string(s) < result)) {
				nmin = depth;
				result = s;
			}
			return false;
		}
		if(x > sum || y > sum || depth > nmin) {
			return false;
		}
		
		if(depth % 2 == 0) {
			s[depth] = 'X';
			if(solve(x + y, y, sum, depth + 1)) return true;
			s[depth] = 'Y';
			if(solve(x, x + y, sum, depth + 1)) return true;
			return false;
		} else {
			s[depth] = 'Y';
			if(solve(x, x + y, sum, depth + 1)) return true;
			s[depth] = 'X';
			if(solve(x + y, y, sum, depth + 1)) return true;
			return false;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arg1 = "XXYYX"; verify_case(0, Arg1, minProg(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "XX"; verify_case(1, Arg1, minProg(Arg0)); }
	void test_case_2() { int Arg0 = 20; string Arg1 = "XYYYYXX"; verify_case(2, Arg1, minProg(Arg0)); }
	void test_case_3() { int Arg0 = 34; string Arg1 = "XYXYXYX"; verify_case(3, Arg1, minProg(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TwoRegisters ___test; 
	repb(i, 1, 10000) {
		if(___test.minProg(i) != ___test.other(i)) {
			printf("%i\n", i);
			break;
		}
		//printf("%i: %s\n", i, ___test.minProg(i).c_str());
	}
	___test.run_test(-1); 
} 
// END CUT HERE 
