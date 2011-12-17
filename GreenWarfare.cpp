#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) reptbc(int, i, b, n, c)
#define reps(i, n) repbs(i, 0, n)
#define repbs(i, b, n) reptbc(unsigned int, i, b, n.size(), <)
#define reptbc(t, i, b, n, c) for(t i = b; i c n; i++)

using namespace std;

class GreenWarfare {
	public:
	int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius) {
		int res;

		

		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 14; verify_case(0, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 8; verify_case(1, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,4,2,3,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1,2,5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 5; int Arg7 = 12; verify_case(2, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-10,-10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,-10,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10,10,-10}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {10,-10,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 10; int Arg7 = 200; verify_case(3, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0,0,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 14; verify_case(4, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GreenWarfare __test;
	__test.run_test(-1);
	system("pause");
}
// END CUT HERE
