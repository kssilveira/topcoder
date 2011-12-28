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

typedef unsigned long long ull;

const ull MOD = ull(1e9 + 7);
const int MAX = 200010;


ull dp[21][MAX];

ull dp_comb[MAX][3];

ull comb(int n, int k) {
  if (n < 0 || n < k) return 0;
  return dp_comb[n][k];
}
 
ull calc(int i, int sum, const vector<int>& points, const vector<string>& description) {
  bool in[3] = {0};
  ull res = 0;
  int num = 0;
  r(j, 3) {
    if (description[i][j] == 'Y') {
      in[j] = true;
      num++;
    }
  }

  if (num == 1) {
    return 1;
  }

  res = comb(sum - 1, num - 1);
  res %= MOD;
  if (num > 1) {
    r(j, 3) {
      if (in[j]) {
        res += MOD - comb(sum - 1 - points[j], num - 1);
        res %= MOD;
      }
    }
  }
  if (num == 3) {
    res += comb(sum - 1 - points[0] - points[1], num - 1);
    res %= MOD;
    res += comb(sum - 1 - points[0] - points[2], num - 1);
    res %= MOD;
    res += comb(sum - 1 - points[1] - points[2], num - 1);
    res %= MOD;
  }

  //printf("calc(%i %i) = ", i, sum);
  //cout << res % MOD << endl;
  return res % MOD;
}

class SRMIntermissionPhase {
	public:
	int countWays(vector <int> points, vector <string> description) {
    dp_comb[0][0] = dp_comb[1][0] = dp_comb[1][1] = 1;
    rb(i, 2, MAX) {
      r(j, min(4, i)) {
        dp_comb[i][j] = dp_comb[i - 1][j - 1] + dp_comb[i - 1][j];
        dp_comb[i][j] %= MOD;
      }
      if (i < 4)
        dp_comb[i][i] = 1;
    }
		ull res = 0;
    memset(dp, 0, sizeof(dp));
    int n = s(description);
    r(j, points[0] + points[1] + points[2] + 1) {
      dp[n][j] = 1;
    }
    bool any = false;
    for (int i = 0; i < n; i++) {
      r(j, 3) {
        if (description[i][j] == 'Y') {
          any = true;
          break;
        }
      }
      if (any) break;
    }

    for (int i = n - 1; i >= 0; i--) {
      int maxsum = 0;
      r(j, 3) {
        if (description[i][j] == 'Y') {
          maxsum += points[j];
        }
      }
      cout << "i: " << i << " maxsum:" << maxsum << endl;
      if (maxsum == 0) {
        dp[i][0] = 1;
      } else {
        dp[i][0] = 0;
      }
      for (int j = 1; j <= maxsum; j++) {
        dp[i][j] = dp[i][j - 1];
        dp[i][j] += calc(i, j, points, description) * dp[i + 1][j - 1];
        dp[i][j] %= MOD;
      }
      for (int j = maxsum + 1; j < MAX; j++) {
        dp[i][j] = dp[i][maxsum];
      }
      if (i == 0) {
        if (maxsum > 0) {
          cout << "dp1: " << dp[0][maxsum] << " dp2: " <<
            dp[0][maxsum - 1] << endl;
          //res = dp[0][maxsum] - dp[0][maxsum - 1];
          res = dp[0][maxsum];
        } else {
          if (any) res = 0;
          else res = 1;
        }
      }
    }
    //for (int j = 0; j < MAX; j++) {
      //res = max(res, dp[0][j]);
    //}

    for(int i = 0; i <= n; i++) {
      for (int j = 0; j < 20; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl; //*/
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25000, 50000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25000; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {30000, 60000, 90000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 799969993; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {25000, 45000, 110000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25600, 51200, 102400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 867560805; verify_case(3, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SRMIntermissionPhase ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
