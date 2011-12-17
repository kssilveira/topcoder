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
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)
 
#define s(v) ((int) v.size())
 
using namespace std;
 
class ShufflingMachine {
	public:
	double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K) {
		double res;
 
 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.8; verify_case(1, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,0,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0; verify_case(2, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,4,3,5,2,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0526315789473684; verify_case(3, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3,4,7,2,8,5,6,1,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arr2[] = {6,3,5,2,8,7,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; double Arg4 = 6.297872340425532; verify_case(4, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	ShufflingMachine ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
