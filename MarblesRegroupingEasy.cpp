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
 
class MarblesRegroupingEasy {
	public:
	int minMoves(vector <string> boxes) {
		int res = 0;
		int n = (int) boxes.size(),
				m = (int) boxes[0].size();

		int cnt[60] = {0};
		int color[60] = {0};
 
		bool joker = false;
		bool got[60] = {false};
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(boxes[i][j] - '0') {
					cnt[i]++;
					color[i] = j;
				}
			}
		}

		for(int i = 0; i < n; i++) {
			int j = color[i];
			if(!cnt[i]) continue;
			if(cnt[i] == 1 && !got[j]) {
				//printf("got %i (%i)\n", j, i);
				got[j] = true;
			} else if(!joker) {
				//printf("joker %i\n", i);
				joker = true;
			} else {
				//printf("more %i\n", i);
				res++;
			}
		}
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"20",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"11",
 "11",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"10",
 "10",
 "01",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"11",
 "11",
 "11",
 "10",
 "10",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"020008000070",
 "000004000000",
 "060000600000",
 "006000000362",
 "000720000000",
 "000040000000", 
 "004009003000",
 "000800000000", 
 "020030003000",
 "000500200000",
 "000000300000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, minMoves(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	MarblesRegroupingEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
