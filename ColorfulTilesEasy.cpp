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
//#include <strstream>
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

class ColorfulTilesEasy {
	public:
	int theMin(string room) {
		int res = 0;
		int n = room.size();

		char cur = room[0];
		repb(i, 1, n) {
			int t = 1;
			while(room[i] == cur) {
				i++;
				t++;
			}
			cur = room[i];
			res += t / 2;
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRRRRR"; int Arg1 = 3; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arg0 = "GGGGGGG"; int Arg1 = 3; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arg0 = "BBBYYYYYY"; int Arg1 = 4; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arg0 = "BRYGYBGRYR"; int Arg1 = 0; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arg0 = "RGGBBBRYYB"; int Arg1 = 3; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	ColorfulTilesEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
