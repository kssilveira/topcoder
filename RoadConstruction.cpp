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

class RoadConstruction {
	public:
	int getExitTime(vector <string> currentLanes) {
		int res = 0;
		int m = currentLanes.size();

		int cur[51], yield[51];

		memset(cur, 0, sizeof(cur));
		memset(yield, 0, sizeof(yield));
		bool done = 0;

		while(!done) {
			rep(i, m) {
				if(cur[i] == currentLanes[i].size()) continue;
				if(!yield[i]) {
					bool found = false;
					repb(j, i + 1, m) {
						if(cur[j] != currentLanes[j].size()) {
							found = true;
						}
					}
					if(found) {
						yield[i] = true;
						continue;
					}
				} {
					yield[i] = false;
					if(currentLanes[i][cur[i]] == 'D') {
						done = true;
						break;
					} else {
						printf("Car: %c\n", currentLanes[i][cur[i]]);
						res++;
						cur[i]++;
						//i--;
					}
					break;
				}
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
	void test_case_0() { string Arr0[] = {"AB",
 "CD",
 "E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getExitTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"AH",
 "D",
 "BCG",
 "E",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getExitTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA",
 "A",
 "AAA",
 "A",
 "AAD",
 "A",
 "AAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, getExitTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"DEFGHIJK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getExitTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"I",
 "WANT",
 "TO",
 "DRINK",
 "SOME",
 "COFFEE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, getExitTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RoadConstruction ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 