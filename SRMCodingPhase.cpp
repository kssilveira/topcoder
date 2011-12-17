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
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)
 
#define s(v) ((int) v.size())
 
using namespace std;
 
class SRMCodingPhase {
	public:
	int countScore(vector <int> points, vector <int> skills, int luck) {
		int res = 0;
    int n = 3;
    int coef[] = {2, 4, 8};
    r(mask, 8) {
      r(l0, luck + 1) {
        r(l1, luck + 1 - l0) {
          int ls[] = {l0, l1, luck - l0 - l1};
        int cur = 0;
        int cur_time = 0;
        r(i, 3) {
          int l = ls[i];
          if (mask & (1 << i)) {
            int t = skills[i];
            if (l >= t) {
              t = 1;
            } else if(l >= 0) {
              t -= l;
            }
            cur += points[i] - coef[i] * t;
            cur_time += t;
          }
        }
        if (cur_time <= 75 && cur > res) {
          res = cur;
        }
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
	void test_case_0() { int Arr0[] = {250, 500, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1310; verify_case(0, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {300, 600, 900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 65, 90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 680; verify_case(1, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {250, 550, 950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 75; int Arg3 = 1736; verify_case(2, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {256, 512, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 30, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1216; verify_case(3, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {300, 600, 1100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {80, 90, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, countScore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SRMCodingPhase ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
