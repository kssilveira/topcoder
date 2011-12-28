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

bool comp(const string& s, const string& r) {
  int n = s(s);
  ri {
    if (s[i] == r[i]) continue;
    int c = s[i], d = r[i];
    if (c == '?') return true;
    if (d == '?') return false;
    if (c == '0') return true;
    if (d == '0') return false;
  }
}

int n, m;
vector<string> rows, columns;

bool compatible(int ind, int col) {
  ri {
    char c = rows[i][ind], d = columns[col][i];
    if (c == d || c == '?' || d == '?') continue;
    return false;
  }
  return true;
}

void fillit(int ind, int col) {
  ri {
    char& c = rows[i][ind];
    char& d = columns[col][i];
    if (c == '?') c = d;
    if (d == '?') d = c;
    if (c == '?') c = d = '0';
  }
}

bitset<100> used;
int res[100];
bool isComp[100][100];
bitset<1 << 30> gone;

bool Solve(int ind, int mask) {
  if (gone[mask]) return false;
  gone[mask] = true;
  //cout << "ind: " << ind << endl;
  if (ind == m) {
    r(ind, m) {
      fillit(ind, res[ind]);
      //cout << res[ind] << ' ';
    }
    //cout << "FOUND!" << endl;
    return true;
  }
  rjm {
    if (used[j]) continue;
    //if (compatible(ind, j)) {
    if (isComp[ind][j]) {
      used[j] = true;
      res[ind] = j;
      bool next = Solve(ind + 1, mask | (1 << j));
      if (next) return true;
      used[j] = false;
    }
  }
  return false;
}
 
class P8XMatrixRecovery {
	public:
	vector <string> solve(vector <string> Rows, vector <string> Columns) {
    used.reset();
    gone.reset();
    rows = Rows;
    columns = Columns;

		vector <string> res;

    sort(columns.begin(), columns.end(), comp);

    n = s(rows), m = s(columns);
    /*
    rim {
      cout << columns[i] << endl;
    }//*/

    rim {
      rjm {
        isComp[i][j] = compatible(i, j);
      }
    }

    Solve(0, 0);

		return rows;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"10?"
,"?11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01"
,"10"
,"1?"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"101", "011" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0"
,"?"
,"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0?1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0", "0", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"
,"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10"
,"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10", "01" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"??0"
,"11?"
,"?01"
,"1?1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1???"
,"?111"
,"0?1?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"010", "110", "101", "101" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	P8XMatrixRecovery ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
