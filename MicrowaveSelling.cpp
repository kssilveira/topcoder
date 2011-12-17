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
 
class MicrowaveSelling {
	public:
	int mostAttractivePrice(int minPrice, int maxPrice) {
		int res = 1;
		int tmp = maxPrice;
 
		while(tmp > 9) {
			tmp /= 10;
			res *= 10;
		}
 
		//cout << "res: " << res << " maxPrice: " << maxPrice << endl;
		//cout << "rr: " << res - 1 + maxPrice * res << endl;

		int lres = res;
		tmp = maxPrice;
		while(1) {
			tmp = maxPrice / res;
			cout << "lres: " << lres << " +: " << lres - 1 + tmp * res << " -: " << lres - 1 + (tmp - 1) * res << endl;
			if(lres == 1) return maxPrice;
			if(lres - 1 + tmp * res > maxPrice) {
				if(lres - 1 + (tmp - 1) * res < minPrice) {
					lres /= 10;
					res /= 10;
					continue;
					return maxPrice;
				}
				return lres - 1 + (tmp - 1) * res;
			} else if(lres - 1 + tmp * res < minPrice) {
					lres /= 10;
					res /= 10;
					continue;
				return maxPrice;
			}
			return lres - 1 + tmp * res;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 460; int Arg1 = 680; int Arg2 = 599; verify_case(0, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1000; int Arg2 = 999; verify_case(1, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1255; int Arg1 = 2999; int Arg2 = 2999; verify_case(2, Arg2, mostAttractivePrice(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 25; int Arg2 = 25; verify_case(3, Arg2, mostAttractivePrice(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	MicrowaveSelling ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
