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

class TwoSidedCards {
	public:
	int theCount(vector <int> taro, vector <int> hanako) {
		int res;

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 8, 1, 2, 3, 4, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2177280; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {41, 22, 17, 36, 26, 15, 10, 23, 33, 48, 49, 9, 34, 6, 21, 2, 46, 16, 25, 3, 24, 13, 40, 37, 35,
50, 44, 42, 31, 12, 29, 7, 43, 18, 30, 19, 45, 32, 39, 14, 8, 27, 1, 5, 38, 11, 4, 20, 47, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 6, 23, 35, 17, 7, 50, 2, 33, 36, 12, 31, 46, 21, 30, 13, 47, 22, 44, 4, 25, 24, 3, 15, 20,
48, 10, 28, 26, 18, 5, 45, 49, 16, 40, 42, 43, 14, 1, 37, 29, 8, 41, 38, 9, 11, 34, 32, 39, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 529165844; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TwoSidedCards ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
