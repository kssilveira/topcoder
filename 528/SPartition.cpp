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

typedef long long ll;

int mask;
int n;
string s;

ll memo[42][42];
bool gone[42][42];

ll solve(int a, int i) {
  ll& res = memo[a][i];
  if (gone[a][i]) return res;
  gone[a][i] = 1;

  //cout << "solve " << a << ' ' << i << endl;
  if (a == n / 2 && i == n) {
    return res = 1;
  }
  if (i == n) return res = 0;
  if (a > n / 2) return res = 0;
  if (i - a > n / 2) return res = 0;
  res = 0;
  if (s[i] == ((mask >> a) & 1)) {
    res += solve(a + 1, i + 1);
  }
  if (s[i] == ((mask >> (i - a)) & 1)) {
    res += solve(a, i + 1);
  }
  return res;
}
 
class SPartition {
	public:
	long long getCount(string S) {
    s = S;
		long long res = 0;
    n = s(s);
    //cout << "n: " << n << endl;
    ri {
      if (s[i] == 'o') s[i] = 0;
      else s[i] = 1;
      //cout << (int) s[i] << ' ';
    }
    for (mask = 0; mask < (1 << (n / 2)); mask++) {
      //cout << "mask: " << mask << endl;
      memset(gone, 0, sizeof(gone));
      res += solve(0, 0);
    }
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxox"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
	void test_case_5() { string Arg0 = "ooxxoxox"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SPartition ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
