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

typedef long double ld;
typedef long long ll;
 
class CorrectMultiplication {
	public:
	long long getMinimum(int A, int B, int C) {
    ll a = A, b = B, c = C;

		long long res = abs(c - a * b);

    ld realk = pow(a + b + c * c, 1./4);
    cout << realk << endl;
    ll llk = realk;
    const ll range = 1000000;
    //*
    for (ll k = max(llk - range, 1LL); k < realk + range; k++) {
      if (c / k == 0) break;
      res = min(res, abs(a - k) + abs(b - c / k) + abs(c - k * (c / k)));
      res = min(res, abs(b - k) + abs(a - c / k) + abs(c - k * (c / k)));
    }//*/

    realk = b * (c + a) / (ld)(b + 1);
    cout << realk << endl;
    llk = realk;
    for (ll k = max(llk - range, (ll)b); k < realk + range; k++) {
      res = min(res, abs(a - k / b) + abs(b - k/(k / b)) +
          abs(c - (k / b) * (k/(k/b))));
    }
 
    swap(a, b);
    realk = b * (c + a) / (ld)(b + 1);
    cout << realk << endl;
    llk = realk;
    for (ll k = max(llk - range, (ll)b); k < realk + range; k++) {
      res = min(res, abs(a - k / b) + abs(b - k/(k / b)) +
          abs(c - (k / b) * (k/(k/b))));
    }

    realk = sqrt(c);
    cout << realk << endl;
    llk = realk;
    for (ll k = max(llk - range, (ll)1); k < realk + range; k++) {
      res = min(res, abs(a - k) + abs(b - k) +
          abs(c - k * k));
    }

    realk = c / (ld) a;
    cout << realk << endl;
    llk = realk;
    for (ll k = max(llk - range, (ll)1); k < realk + range; k++) {
      res = min(res, abs(a) + abs(b - k) +
          abs(c - a / k));
    }

    /*
    cout << res << endl;
    for (ll a1 = max(a - res, (ll)1); a1 <= a + res; a1++) {
      for (ll b1 = max(b - res, (ll)1); b1 <= b + res; b1++) {
        res = min(res, abs(a - a1) + abs(b - b1) + abs(c - a1 * b1));
        a1 = max(a1, a - res);
        b1 = max(b1, b - res);
      }
    }//*/
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 19; int Arg1 = 28; int Arg2 = 522; long long Arg3 = 2LL; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 30; int Arg2 = 500; long long Arg3 = 11LL; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11111; int Arg1 = 11111; int Arg2 = 123454321; long long Arg3 = 0LL; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 100; int Arg2 = 10; long long Arg3 = 1089LL; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 399; int Arg1 = 522; int Arg2 = 199999; long long Arg3 = 24LL; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	CorrectMultiplication ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
