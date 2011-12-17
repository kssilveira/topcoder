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
 
#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)
 
using namespace std;
 
class CarrotBoxes {
	public:
	double theProbability(vector <string> information) {
		int n = (int) information.size();

		for(int t = 0; t < n; t++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(information[i][j] == 'Y') {
						for(int k = 0; k < n; k++) {
							if(information[j][k] == 'Y')
								information[i][k] = 'Y';
						}
					}
				}
			}
		}
 
		bool open[60] = {false}, know[60] = {false};
		int total = 0, nopen = 0;
		while(total < n - 1) {
			int mcnt = 0, mi = 0;
			for(int i = 0; i < n; i++) {
				if(open[i]) continue;
				int cnt = 0;
				for(int j = 0; j < n; j++) {
					if(information[i][j] == 'Y' && !know[j]) {
						cnt++;
					}
				}
				if(cnt > mcnt) {
					mcnt = cnt;
					mi = i;
				}
			}
			//cout << "mi: " << mi << endl;
			open[mi] = true;
			for(int j = 0; j < n; j++) {
				if(information[mi][j] == 'Y')
					know[j] = true;
			}
			total += mcnt;
			nopen++;
		}
 
		return (n - nopen) / (long double) n;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYYYY",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(0, Arg1, theProbability(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNNNN",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, theProbability(Arg0)); }
	void test_case_2() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, theProbability(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNNN",
 "YYNNN",
 "YNYNN",
 "NNNYY",
 "NNNYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.6; verify_case(3, Arg1, theProbability(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYYNNNYN",
 "NYNNNNYN",
 "NNYNNNNN",
 "NYNYNNNN",
 "YNNNYNNY",
 "NNYNNYNN",
 "NNNNYNYN",
 "NNYNNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.875; verify_case(4, Arg1, theProbability(Arg0)); }
	void test_case_5() { string Arr0[] = {"YNNNNNNNNYNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNYNNNNNYNNN",
 "NNNYNYNNNNNNNNYNNNNN",
 "NNNNYNNNNNNNNNYNNNNY",
 "NNNNNYNNNNNNNNNNNNNY",
 "NNNNYNYNYNNNNNNNNNNN",
 "NNNNNNNYNNNYYNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNN",
 "YNNNNNNNNYNNNNNYNNNN",
 "NNNNNNNNNNYNNNNNNNNN",
 "NYNNNNNNNNNYNNNNNNNN",
 "NNNNNNNYNNNNYNNNNNNN",
 "NNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNNNNYNNYNNNYN",
 "NYNNNNNNNNNNNNNYNNNN",
 "NNYNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNYNYNN",
 "NNNNNNNNYNYNNNNNNNYY",
 "NNNYNNNNNNNNNNNNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.75; verify_case(5, Arg1, theProbability(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	CarrotBoxes ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
