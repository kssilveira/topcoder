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
 
class RussianSpeedLimits {
	public:
	int getCurrentLimit(vector <string> signs) {
		int n = (int) signs.size();

		int cur = 60;
		int def[] = {60, 90};
		int city = 0;
		rep(i, n) {
			if(signs[i] == "default") {
				cur = def[city];
			} else if(signs[i] == "city") {
				city = 1 - city;
				cur = def[city];
			} else {
				sscanf(signs[i].c_str(), "%i", &cur);
			}
		}

 
 
 
		return cur;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"80"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80; verify_case(0, Arg1, getCurrentLimit(Arg0)); }
	void test_case_1() { string Arr0[] = {"40", "70", "default", "20", "50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(1, Arg1, getCurrentLimit(Arg0)); }
	void test_case_2() { string Arr0[] = {"40", "70", "default"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(2, Arg1, getCurrentLimit(Arg0)); }
	void test_case_3() { string Arr0[] = {"40", "80", "city"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(3, Arg1, getCurrentLimit(Arg0)); }
	void test_case_4() { string Arr0[] = {"city", "60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(4, Arg1, getCurrentLimit(Arg0)); }
	void test_case_5() { string Arr0[] = {"city", "50", "default"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(5, Arg1, getCurrentLimit(Arg0)); }
	void test_case_6() { string Arr0[] = {"city", "city", "city", "city"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(6, Arg1, getCurrentLimit(Arg0)); }
	void test_case_7() { string Arr0[] = {"20", "city", "city", "50", "60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(7, Arg1, getCurrentLimit(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RussianSpeedLimits ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
