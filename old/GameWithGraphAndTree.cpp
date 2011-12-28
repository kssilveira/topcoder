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

class GameWithGraphAndTree {
	public:
	int calc(vector <string> graph, vector <string> tree) {
		int res;

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNN",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYNNN",
 "YNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNN", 
 "YNYNN",
 "NYNYN",
 "NNYNY",
 "NNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN", 
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNYYN", 
 "NNYNNN",
 "NYNNYY", 
 "YNNNNN",
 "YNYNNN",
 "NNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYNNY",
 "YNNNNNNYN",
 "NNNNYYNYY",
 "NNNNNYNNY",
 "NNYNNNYNY",
 "YNYYNNNYN",
 "NNNNYNNYN",
 "NYYNNYYNN",
 "YNYYYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYNNNYYN",
 "NNNNYNNNN",
 "YNNNNNNNN",
 "NNNNNNYNN",
 "NYNNNNNYY",
 "NNNNNNNNY",
 "YNNYNNNNN",
 "YNNNYNNNN",
 "NNNNYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 90; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	GameWithGraphAndTree ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
