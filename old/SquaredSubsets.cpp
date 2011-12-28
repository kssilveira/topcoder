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
#define ppn(x) printf("%s: %d\n", #x, x);
 
using namespace std;
 
class SquaredSubsets {
	public:
	long long countSubsets(int S, vector <int> x, vector <int> y) {
		long long res = 0;
    vector<pair<int, int> > v;
    int n = s(x);
    ri {
      v.push_back(make_pair(x[i], y[i]));
    }
    sort(v.begin(), v.end());
    ri {
      printf("(%d, %d) ", v[i].first, v[i].second);
    }
    cout << endl;
    ri {
      int bx = v[i].first;
      ppn(i);
      ppn(bx);
      rb(j, i + 1, n) {
        ppn(j);
        ppn(v[j].first - bx);
        if (v[j].first - bx > S) break;
        int by = v[j].second;
        ppn(by);
        if (v[i].second - by > S || v[i].second - by < 0) continue;
        int cnt = 0;
        rb(k, i, n) {
          if (v[k].first - bx  <= S &&
              v[k].first - bx >= 0 &&
              v[k].second - by <= S &&
              v[k].second - by >= 0) {
            cnt++;
          }
        }
        ppn(cnt);
        res += 1 << (cnt - 2);
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
	void test_case_0() { int Arg0 = 5; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(0, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {-5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100000000; int Arr1[] = {-1,-1,-1,0,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,0,1,1,-1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 21LL; verify_case(2, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 66LL; verify_case(3, Arg3, countSubsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(4, Arg3, countSubsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	SquaredSubsets ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
