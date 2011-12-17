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

int temp;

class RooksParty {
	public:
	int countArrangements(int rows, int columns, vector <int> counts) {
		int res = 0;

		calc(0, 0, 0, counts[0]);

		return res;
	}
	
	void calc(int cur, int line, int sum, int curcount)
	{
		if(curcount == 0) {
			if(cur == counts.size() - 1) {
				// calcula
				printf("-----\n");
				rep(i, cur) {
					printf("%i ", lines[cur]);
			} else {
				if(line == rows) {
					// zero
					return;
				} else {
					lines[cur] = line;
					calc(cur + 1, line + 1, sum + counts[cur], counts[cur + 1]);
				}
			}
		} else if(line == rows) {
			// zero
			return;
		}
		repbe(i, 1, min(curcount, columns)) {
			if(cur == 0 && line == 0) {
				temp = 1;
			}
			temp *= comb(columns - sum, cur);
			calc(cur, line + 1, curcount - cur);
		}
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(0, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(1, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 8; int Arr2[] = {1,1,1,1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 625702391; verify_case(3, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, countArrangements(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RooksParty ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
