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
 
class SkewedPerspectives {
	public:
	vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
		vector <string> res;

    r(T, s(views)) {
      string view = views[T];
      int n = s(view);
      if (!view.empty() && view[0] == 'b' && (view.size() == 1 || view[1] != 'b')) {
          res.push_back("invalid");
          continue;
      }
      int cnt[3] = {0}, extra = 0, nb = 0, other = 0;
      int first = -1;
      int nw = 1;
      ri {
        if (view[i] != 'b') {
          cnt[view[i] - '0']++;
          first = -1;
        } else if (i == n - 1 || view[i + 1] != 'b') {
          nw++;
          if (first == -1) {
            first = i - 1;
          }
          if (first < 0) {
            first += 2;
          }
          nb++;
          extra += first;
          if ((first) % 2) {
            other++;
          }
        } else {
          if (first == -1) {
            first = i - 1;
          }
          nb++;
          i++;
        }
      }
      if (T == 4) {
      /*
      r(i, 3) {
        printf("%d ", cnt[i]);
      }
      printf(" extra %d other %d nb %d\n", extra, other, nb);//*/
      }
      if (cnt[0] > cubes[0] || cnt[1] > cubes[1] || cnt[2] > cubes[2] ||
          nb > B ||
          (cubes[0] - cnt[0] + cubes[1] - cnt[1] + cubes[2] - cnt[2] + 
           2 * (B - nb)) < extra ||

          (cubes[0] - cnt[0] + cubes[1] - cnt[1] + cubes[2] - cnt[2]) < other || nw > w) {
        res.push_back("invalid");
      } else {
        res.push_back("valid");
      }
    }
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arr3[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0", "bb"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"00b0b", "bbbbbbbb", "000b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SkewedPerspectives ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
