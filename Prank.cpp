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
 
class Prank {
	public:
	vector <int> realWeight(int apparentGain) {
		vector <int> res;
		set<int> s;
 
		repbe(e, 1, apparentGain) {
			if(!(apparentGain % e) && !((apparentGain / e - e) % 2)) {
				int l = (apparentGain / e - e) / 2 + e;
				//cout << "e: " << e << endl;
				if(!s.insert(l).second)
					res.push_back(l);
			}
		}
				
					

				/*
			n² - l² = d


			(l + e)² - l² = d
			2le + e² = d
			e(2l + e) = d
			2l + e = d/e
			//*/
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 233; int Arr1[] = {117 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, realWeight(Arg0)); }
	void test_case_1() { int Arg0 = 15; int Arr1[] = {4, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, realWeight(Arg0)); }
	void test_case_2() { int Arg0 = 1440; int Arr1[] = {38, 39, 42, 46, 49, 53, 66, 77, 94, 123, 182, 361 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, realWeight(Arg0)); }
	void test_case_3() { int Arg0 = 100000; int Arr1[] = {325, 350, 550, 665, 1025, 1270, 2510, 3133, 5005, 6254, 12502, 25001 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, realWeight(Arg0)); }
	void test_case_4() { int Arg0 = 93301; int Arr1[] = {3595, 46651 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, realWeight(Arg0)); }
	void test_case_5() { int Arg0 = 16; int Arr1[] = {5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, realWeight(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	Prank ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
