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

class SequenceMerger {
	public:
	vector <int> getVal(vector <string> seqs, vector <int> positions) {
		vector <int> res;

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"E 1 1000000000 1000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1000000000, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getVal(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A 1 1 10", "G 1 2 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9, 10, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getVal(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A 1000000000 1000000000 1000000000","G 100000000000000000 1000000000000 100000000000000", "E 1000000000000000 10000000 10 1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 1111, 10000000, 1000000000, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getVal(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"G 1 1 999999999", "E 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,999999999,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getVal(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A 100 341 1524", "G 1 3 45235", "E 653 87 12341 8785 123 543"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100000,1,10,10000,100,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1, 1, 441, -1, 28403, 334621 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getVal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	SequenceMerger ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
