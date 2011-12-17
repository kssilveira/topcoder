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

class Trio
{
public:
	Trio(int x, int y): x(x), y(y) {}
	int x, y, z;
};

bool comp1(Trio l, Trio r)
{
	return l.x < r.x;
}

bool comp2(Trio l, Trio r)
{
	return l.y < r.y;
}

class SortingWithPermutation {
	public:
	vector <int> getPermutation(vector <int> a) {
		vector<int> res;
		vector<Trio> temp;

		rep(i, a.size())
			temp.push_back(Trio(a[i], i));

		stable_sort(temp.begin(), temp.end(), comp1);

		rep(i, temp.size())
			temp[i].z = i;

		sort(temp.begin(), temp.end(), comp2);

		rep(i, temp.size())
			res.push_back(temp[i].z);

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPermutation(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 1, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPermutation(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 1, 6, 1, 3, 6, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 0, 6, 1, 3, 7, 2, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPermutation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	SortingWithPermutation ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
