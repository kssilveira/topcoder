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

class RightTriangle {
	public:
	long long triangleCount(int places, int points, int a, int b, int c) {
		long long res = 0;
		bool used[1000001];
		memset(used, 0, sizeof(used));

		if(places < 4 || places % 2 == 1) {
			return 0;
		}

		a %= places;
		b %= places;
		c %= places;

		rep(i, points) {
			int n = i % places;
			int p = (((a * n) % places) * n) % places;
			p += (b * n) % places;
			p %= places;
			p += c;
			p %= places;
			//printf("p: %i\n", p);
			for(int j = p; ; j = (j + 1) % places) {
				if(!used[j]) {
					used[j] = 1;
					//printf("Using %i\n", j);
					break;
				}
			}
		}

		rep(i, places / 2) {
			if(used[i] && used[i + places / 2]) {
				res += points - 2;
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
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 0; int Arg3 = 3; int Arg4 = 0; long long Arg5 = 0LL; verify_case(0, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 40; int Arg1 = 3; int Arg2 = 5; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1LL; verify_case(1, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 16; int Arg3 = 24; int Arg4 = 17; long long Arg5 = 4LL; verify_case(2, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 47000; int Arg2 = 0; int Arg3 = 2; int Arg4 = 5; long long Arg5 = 0LL; verify_case(3, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 200000; int Arg1 = 700; int Arg2 = 123456; int Arg3 = 789012; int Arg4 = 345678; long long Arg5 = 6980LL; verify_case(4, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RightTriangle ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
