#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cstring>
#include <climits>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

#include <cmath>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

bool found[1000010];

class SquareFreeNumbers {
	public:
	int getCount(long long min, long long max) {
		int res = max - min + 1;

		memset(found, 0, sizeof(found));

		for(long long i = MAX(sqrt(min), 2); i * i <= max; i++) {
			if(i * i < min) continue;
			for(int k = 1; k * i * i <= max; k++) if(!found[k * i * i - min]) {
				found[k * i * i - min] = true;
				res--;
			//cout << "i: " << i << "res: " << res;
			}
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; int Arg2 = 7; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 15LL; int Arg2 = 1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000LL; int Arg2 = 608; verify_case(2, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	SquareFreeNumbers ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
