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

unsigned long long s(unsigned long long i)
{
	//cout << "i: " << i << endl;
	unsigned long long res = 0;
	while(i) {
		res += i % 10;
		i /= 10;
	}
	return res;
}

int pot[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 1000000001};
 
class RabbitNumber {
	public:
	int theCount(int low, int high) {
		int res = 0;

		int i = low;
		repb(j, 1, 11) {
			//printf("j: %i\n", j);
			if(i > high) break;
			while(i < pot[j] && i <= high) {
				unsigned long long si = s(i);
				unsigned long long si2 = si * si;
				unsigned long long i2 = i * (unsigned long long) i;
				if(si2 <= 18 * j) {
					if(si2 == s(i2)) res++;
					i++;
				} else {
					repb(k, 1, 11) {
						int mod = i % pot[k];
						if(mod) {
							i += pot[k] - (mod);
							break;
						}
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 22; int Arg1 = 22; int Arg2 = 1; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 484; int Arg1 = 484; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 12; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; int Arg1 = 484; int Arg2 = 24; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RabbitNumber ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
