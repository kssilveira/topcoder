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

#define ERROR "CHEATER"

class DietPlan {
	public:
	string chooseDinner(string diet, string breakfast, string lunch) {
		bool in[256];
		string res;

		memset(in, 0, sizeof(in));

		int n = diet.size();
		rep(i, n) {
			in[diet[i]] = 1;
		}

		rep(i, breakfast.size()) {
			if(!in[breakfast[i]]) {
				return ERROR;
			} else {
				in[breakfast[i]] = 0;
			}
		}

		rep(i, lunch.size()) {
			if(!in[lunch[i]]) {
				return ERROR;
			} else {
				in[lunch[i]] = 0;
			}
		}

		rep(i, 256) {
			if(in[i]) {
				res.push_back(i);
			}
		}

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "AB"; string Arg2 = "C"; string Arg3 = "D"; verify_case(0, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ABEDCS"; string Arg1 = ""; string Arg2 = ""; string Arg3 = "ABCDES"; verify_case(1, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "EDSMB"; string Arg1 = "MSD"; string Arg2 = "A"; string Arg3 = "CHEATER"; verify_case(2, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = ""; string Arg1 = ""; string Arg2 = ""; string Arg3 = ""; verify_case(3, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "IWANTSODER"; string Arg1 = "SOW"; string Arg2 = "RAT"; string Arg3 = "DEIN"; verify_case(4, Arg3, chooseDinner(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	DietPlan ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
