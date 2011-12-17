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

typedef long long ll;
 
using namespace std;

vector<int> to_v(int x) {
  vector<int> res;
  while (x) {
    res.push_back(x % 10);
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

const int D = 12;

ll comb[D + 5][D + 5];
ll pot8[D + 5];

ll ways(int n4, int n7, int x) {
  vector<int> v = to_v(x);
  int n = s(v);
  ll res = 0;
  ri {
    r(d, v[i]) {
      int r4 = n4, r7 = n7;
      if (d == 4) r4--;
      if (d == 7) r7--;
      int rest = n - i - 1;
      if (r4 >= 0 && r7 >= 0 && r4 + r7 <= rest) {
        res += comb[rest][r4] * comb[rest - r4][r7] * pot8[rest - r4 - r7];
      }
    }
    if (v[i] == 4) n4--;
    if (v[i] == 7) n7--;
  }
  return res;
}

ll sum(int x) {
  ll res = 0;
  r(n4, D) {
    r(n7, D) {
      res += abs(n4 - n7) * ways(n4, n7, x + 1);
    }
  }
  return res;
}
 
class SumOfLuckiness {
	public:
	long long theSum(int A, int B) {
    pot8[0] = 1;
    rb(i, 1, D) {
      pot8[i] = 8 * pot8[i - 1];
      //cout << pot8[i] << ' ';
    }
    r(i, D) {
      comb[i][0] = 1;
      r(j, i) {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      }
      comb[i][i] = 1;
    }
    return sum(B) - sum(A - 1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; long long Arg2 = 2LL; verify_case(0, Arg2, theSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 40; int Arg1 = 47; long long Arg2 = 8LL; verify_case(1, Arg2, theSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 526; long long Arg2 = 231LL; verify_case(2, Arg2, theSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4444; int Arg1 = 7777; long long Arg2 = 2338LL; verify_case(3, Arg2, theSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 585858585; int Arg1 = 858585858; long long Arg2 = 287481025LL; verify_case(4, Arg2, theSum(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SumOfLuckiness ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
