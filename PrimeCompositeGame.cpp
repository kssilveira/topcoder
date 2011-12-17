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

const int MAX = 500000;

bitset<MAX> iscomp;

typedef priority_queue<pair<int, int> > PQ;

int getmin(PQ& q, int bound) {
  while (!q.empty()) {
    pair<int, int> cur = q.top();
    if (cur.second < bound) {
      q.pop();
    } else {
      return -cur.first;
    }
  }
  return 0;
}

int getmax(PQ& q, int bound) {
  while (!q.empty()) {
    pair<int, int> cur = q.top();
    if (cur.second < bound) {
      q.pop();
    } else {
      return cur.first;
    }
  }
  return 0;
}

int dp[2];

#define mp make_pair
#define ppn(x) cout << #x << ": " << x << endl
 
class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
    //ppn(N);
    rb(i, 2, N + 1) {
      if (!iscomp[i]) {
        //cout  << i << endl;
        for (int j = i + i; j <= N; j += i) {
          iscomp[j] = true;
        }
      }
    }
    priority_queue<pair<int, int> > primePositive[2],
      primeNegative[2], compPositive[2], compNegative[2];

    rb(n, 1, N + 1) {
      r(player, 2) {
        dp[player] = 0;
        int pick = 0;
        if (player == 0) {
          pick = getmin(primePositive[1], n - K);
          if (pick == 0) {
            pick = getmin(primeNegative[1], n - K);
          }
        }
        if (player == 1) {
          pick = getmax(compNegative[0], n - K);
          if (pick == 0) {
            pick = getmax(compPositive[0], n - K);
          }
        }
        //ppn(pick);
        if (pick == 0) {
          if (player == 0) {
            dp[player] = -1;
          } else {
            dp[player] = 1;
          }
        } else {
          if (pick < 0) {
            dp[player] = pick - 1;
          } else {
            dp[player] = pick + 1;
          }
        }
      }

      r(player, 2) {
        if (n == 1) break;
        if (iscomp[n]) {
          if (dp[player] > 0) {
            compPositive[player].push(make_pair(dp[player], n));
          } else {
            compNegative[player].push(make_pair(dp[player], n));
          }
        } else {
          if (dp[player] > 0) {
            primePositive[player].push(mp(-dp[player], n));
          } else {
            primeNegative[player].push(mp(-dp[player], n));
          }
        }
      }

    }

    int y = dp[0];
    if (y > 0) return y - 1;
    return y + 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 58; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; int Arg2 = -2; verify_case(2, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1; verify_case(3, Arg2, theOutcome(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 526; int Arg1 = 58; int Arg2 = 19; verify_case(4, Arg2, theOutcome(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	PrimeCompositeGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
