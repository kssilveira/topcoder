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

bool myComp(pair<int, int> l, pair<int, int> r)
{
	return l.first < r.first;
}
 
class LinearTravellingSalesman {
	public:
	int findMinimumDistance(vector <int> x, vector <int> y) {
		int res = 0;
		vector<pair<int, int> > pairs;
 
		if(x[0] != x[1]) {
			rep(i, x.size())
				pairs.push_back(make_pair(x[i], y[i]));
		} else {
			rep(i, x.size())
				pairs.push_back(make_pair(y[i], x[i]));
		}
		/*
		rep(i, x.size())
			printf("(%i, %i) ", pairs[i].first, pairs[i].second);
		printf("\n");
		//*/
		sort(pairs.begin(), pairs.end(), myComp);
		/*
		rep(i, x.size())
			printf("(%i, %i) ", pairs[i].first, pairs[i].second);
		printf("\n");//*/
		repb(i, 1, x.size())
			res += abs(pairs[i].first - pairs[i - 1].first) + abs(pairs[i].second - pairs[i - 1].second);
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,100,1000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,100,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11000; verify_case(2, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {80,60,70,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,70,60,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(3, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {7,7,7,7,7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105,1231,5663,295,3062,380,7777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7672; verify_case(4, Arg2, findMinimumDistance(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	LinearTravellingSalesman ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
