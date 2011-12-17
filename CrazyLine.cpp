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
 
class CrazyLine {
	public:
	int maxCrazyness(vector <int> heights) {
		int res;
		int n = (int) heights.size();

		res = 0;
		rep(i, n - 1) {
			res += abs(heights[i] - heights[i + 1]);
		}

		bool changed = true;
		while(changed) {
			changed = false;
			rep(i, n) {
				rep(j, n) {
					rep(k, n) {
						rep(m, n) {
							int temp = heights[i];
							heights[i] = heights[j];
							heights[j] = heights[k];
							heights[k] = heights[m];
							heights[m] = temp;
							int cur = 0;
							rep(l, n - 1) {
								cur += abs(heights[l] - heights[l + 1]);
							}
							if(cur > res) {
								res = cur;
								changed = true;
							} else {
								int temp = heights[m];
								heights[m] = heights[k];
								heights[k] = heights[j];
								heights[j] = heights[i];
								heights[i] = temp;
							}
						}
					}
				}
			}
			if(!changed) {
				break;
			}
		}

		rep(i, n) {
			printf("%i ", heights[i]);
		}
 
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,10,25,40,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(0, Arg1, maxCrazyness(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,5,7,11,13,17,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; verify_case(1, Arg1, maxCrazyness(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,501}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; verify_case(2, Arg1, maxCrazyness(Arg0)); }
	void test_case_3() { int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, maxCrazyness(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	CrazyLine ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
