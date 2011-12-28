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

bool comp[51][3][51][3][51] = {{{{{0}}}}};
 
class MagicalSquare {
	public:
	long long getCount(vector <string> rowStrings, vector <string> columnStrings) {
    int sizes[2][3];
    r(i, 2) {
      r(j, 3) {
        sizes[i][j] =
          i == 0 ? rowStrings[j].size() : columnStrings[j].size();
      }
    }
    
    r(a, 3) {
      r(b, 3) {
        r(z, 51) {
          r(x, sizes[0][a] + 1 - z) {
            r(y, sizes[1][b] + 1 - z) {
              comp[z][a][x][b][y] = 
                rowStrings[a].substr(x, z) == columnStrings[b].substr(y, z);
            }
          }
        }
      }
    }

		long long res = 0;
    r(a, sizes[0][0] + 1) {
      r(b, sizes[0][0] + 1 - a) {
        r(x, sizes[0][1] + 1) {
          r(y, sizes[0][1] + 1 - x) {
            int c = sizes[0][0] - a - b,
                z = sizes[0][1] - x - y;
            if (!comp[a][0][0][0][0] ||
                !comp[x][1][0][0][a] ||
                !comp[b][0][a][1][0] ||
                !comp[y][1][x][1][b] ||
                !comp[c][0][a + b][2][0] ||
                !comp[z][1][x + y][2][c]) continue;
            int l0 = sizes[1][0] - a - x,
                l1 = sizes[1][1] - b - y,
                l2 = sizes[1][2] - c - z;
            if (l0 + l1 + l2 != sizes[0][2] ||
                !comp[l0][2][0][0][a + x] ||
                !comp[l1][2][l0][1][b + y] ||
                !comp[l2][2][l0 + l1][2][c + z]) continue;
            res++;
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
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"f", "o", "x"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f", "o", "x"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"x", "x", "x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"x", "", "xx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cd", "cd", "cd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"dvd", "dvd", "dvd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"abab", "ab", "abab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abab", "ab", "abab"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 11LL; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"qwer", "asdf", "zxcv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"qaz", "wsx", "erdfcv"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	MagicalSquare ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
