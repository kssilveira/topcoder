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
 
class RowAndCoins {
	public:
	string getWinner(string cells) {
		string res;
    int n = s(cells);
    int cnt[2] = {0};
    cnt[!!(cells[0] == 'B')]++;

    rb(i, 1, n) {
      if (cells[i] != cells[i - 1]) {
        cnt[!!(cells[i] == 'B')]++;
      }
    }

    cout << cnt[0] << endl;
    cout << cnt[1] << endl;

    res = "Alice";
    if (cnt[1] > cnt[0]) res = "Bob";
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBB"; string Arg1 = "Alice"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "BBBB"; string Arg1 = "Bob"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = "BA"; string Arg1 = "Alice"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "BABBABBB"; string Arg1 = "Bob"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = "ABABBBABAABBAA"; string Arg1 = "Alice"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { string Arg0 = "BBBAAABBAAABBB"; string Arg1 = "Bob"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RowAndCoins ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
