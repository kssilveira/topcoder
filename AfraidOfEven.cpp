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
 
class AfraidOfEven {
	public:
	vector <int> restoreProgression(vector <int> a) {
		vector <int> res;
		int n = (int)a.size();
		res.resize(n);

		int r = a[1] - a[0];
		bool found = false;
		rep(i, n) {
			int ai = a[0] + i * r;
			while(!(ai % 2)) ai /= 2;
			if(ai != a[i]) {
				found = true;
					break;
			}
			res[i] = a[0] + i * r;
		}

		if(!found) {
			return res;
		}
		
		r = (a[2] - a[0]) / 2;
		found = false;
		rep(i, n) {
			int ai = a[0] + i * r;
			while(!(ai % 2)) ai /= 2;
			if(ai != a[i]) {
				found = true;
					break;
			}
			res[i] = a[0] + i * r;
		}

		if(!found) {
			return res;
		}

		
		r = (a[3] - a[1]) / 2;
		found = false;
		a[0] = a[1] - r;
		res[0] = a[0];
		repb(i, 1, n) {
			int ai = a[0] + i * r;
			while(!(ai % 2)) ai /= 2;
			if(ai != a[i]) {
				printf("%i %i %i\n", r, i, ai);
				found = true;
					break;
			}
			res[i] = a[0] + i * r;
		}

		if(!found) {
			return res;
		}


		res.clear();
 
		/*
		repb(ii, 1, 6) {
			int i = 2 * ii;
			rep(jj, 4) {
				int j = 2 * jj;
				rep(k, 5) {
					printf("%i ", i + j * k);
				}
				printf("\n");
				rep(k, 5) {
					int l = i + j * k;
					while(!(l % 2)) {
						l /= 2;
					}
					printf("%i ", l);
				}
				printf("\n");
				printf("\n");
			}
		}
		//*/

 
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 3, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, restoreProgression(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 7, 5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 7, 5, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, restoreProgression(Arg0)); }
	void test_case_2() { int Arr0[] = {999, 999, 999, 999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999, 999, 999, 999 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, restoreProgression(Arg0)); }
	void test_case_3() { int Arr0[] = {7, 47, 5, 113, 73, 179, 53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 47, 80, 113, 146, 179, 212 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, restoreProgression(Arg0)); }
	void test_case_4() { int Arr0[] = {749, 999, 125, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1498, 999, 500, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, restoreProgression(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	AfraidOfEven ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
