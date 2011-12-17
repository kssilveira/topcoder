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
 
class NumberMagicEasy {
	public:
	int theNumber(string answer) {
		int res = 0;
		int card[][8] = {{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 9, 10, 11, 12},
			{1, 2, 5, 6, 9, 10, 13, 14},
			{1, 3, 5, 7, 9, 11, 13, 15}};
		int went[17];
		memset(went, 0, sizeof(went));
		rep(i, 4) {
			if(answer[i] == 'N') {
				rep(j, 8) {
					went[card[i][j]] = 1;
				}
			} else {
				repb(j, 1, 17) {
					bool found = false;
					rep(k, 8) {
						if(card[i][k] == j) {
							found = true;
							break;
						}
					}
					if(!found) {
						went[j] = 1;
					}
				}
			}
		}

		repb(i, 1, 17) {
			if(!went[i]) {
				res = i;
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
	void test_case_0() { string Arg0 = "YNYY"; int Arg1 = 5; verify_case(0, Arg1, theNumber(Arg0)); }
	void test_case_1() { string Arg0 = "YNNN"; int Arg1 = 8; verify_case(1, Arg1, theNumber(Arg0)); }
	void test_case_2() { string Arg0 = "NNNN"; int Arg1 = 16; verify_case(2, Arg1, theNumber(Arg0)); }
	void test_case_3() { string Arg0 = "YYYY"; int Arg1 = 1; verify_case(3, Arg1, theNumber(Arg0)); }
	void test_case_4() { string Arg0 = "NYNY"; int Arg1 = 11; verify_case(4, Arg1, theNumber(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	NumberMagicEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
