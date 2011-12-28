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

int go(const string& s, char c) {
  int res = 0;
  r(i, s(s)) {
    if (s[i] == c) res++;
  }
  return res;
}
 
class LoveCalculator {
	public:
	string findBoy(string girl, vector <string> boys) {
    int L, O, V, E;
    int n = s(boys);
    int res = 0, resi = 0;
    ri {
      L = O = V = E = 0;
      L = go(girl, 'L') + go(boys[i], 'L');
      O = go(girl, 'O') + go(boys[i], 'O');
      V = go(girl, 'V') + go(boys[i], 'V');
      E = go(girl, 'E') + go(boys[i], 'E');
      int cur = L + O;
      cur %= 100;
      cur *= L + V;
      cur %= 100;
      cur *= L + E;
      cur %= 100;
      cur *= O + V;
      cur %= 100;
      cur *= O + E;
      cur %= 100;
      cur *= V + E;
      cur %= 100;
      if (cur > res || (cur == res && boys[i] < boys[resi])) {
        res = cur;
        resi = i;
      }
    }
 
		return boys[resi];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LOVE"; string Arr1[] = {"JACOB","FRANK","DANO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "FRANK"; verify_case(0, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JANE"; string Arr1[] = {"THOMAS","MICHAEL","INDY","LIU"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INDY"; verify_case(1, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "LILLY"; string Arr1[] = {"PIERRE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "PIERRE"; verify_case(2, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "MERYLOV"; string Arr1[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "DAVE"; verify_case(3, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LLOL"; string Arr1[] = {"BVERON","CVERON","AVERON","DVERON"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AVERON"; verify_case(4, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "VELYLEOCEVE"; string Arr1[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "VLOLUVCBLLQVESWHEEKC"; verify_case(5, Arg2, findBoy(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	LoveCalculator ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
