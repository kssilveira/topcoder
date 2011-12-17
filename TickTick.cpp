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

typedef unsigned long long ULL;

class TickTick {
	public:
	ULL pot(int n) {
		int res = 1;
		while(n >= 0) {
			res *= 10;
			n--;
		}
		return res;
	}
	int count(vector <string> events) {
		int res = 0;

		// STILL WRONG!
		
		int n = events.size();

		unsigned long long times[51];
		times[0] = 0;
		rep(i, n) {
			char l[10] = {0}, r[10] = {0};
			//cout << "s: " << events[i].c_str() << endl;

			if(!sscanf(events[i].c_str(), "%[^.].%s", l, r)) {
				sscanf(events[i].c_str(), ".%s", r);
			}
			//cout << "l: " << l << " r: " << r << endl;
			//cout << "l: " << atoi(l) << " r: " << atoi(r) << endl;
			times[i] = ((((ULL) atoi(l)) * pot(strlen(r) - 1) + atoi(r)) *(ULL) pot(6 - strlen(r)));
			//cout << "t: " << times[i + 1] << endl;
		}

		rep(i, n) {
			cout << times[i] << endl;
		}
		cout << endl;

		rep(i, n) {
			//repb(j, i + 1, n) {
				if(i < n - 1 && times[i + 1] - times[i] < 10000000
						|| i == 0 && times[i] < 10000000) {
					res++;
				}
			//}
		}

		return res + 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".222","00.223","1.221","4.220"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"4.220112","4.221","4.222","4.223"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"123456.1","123456.7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TickTick ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
