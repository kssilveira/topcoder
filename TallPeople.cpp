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

class TallPeople {
	public:
	vector <int> getPeople(vector <string> people) {
		vector <int> res;

		
		int hg[51][51];

		int n = people.size();
		int m = 0;

		rep(i, n) {
			int val = 0;
			int j = 0;
			int k = 0;
			for(; j < people[i].size(); j++) {
				val = 0;
				while(people[i][j] != ' ' && j < people[i].size()) {
					val+= people[i][j] - '0';
					val *= 10;
					j++;
				}
				hg[i][k] = val / 10;
				k++;
			}
			m = k;
		}

		/*
		rep(i, n) {
			rep(k, m) {
				printf("%i ", hg[i][k]);
			}
			printf("\n");
		}
		//*/

		int sht = 10000, tal = 0;
		rep(i, n) {
			sht = 10000;
			rep(j, m) {
				if(hg[i][j] < sht) {
					sht = hg[i][j];
				}
			}
			if(sht > tal) {
				tal = sht;
			}
		}
			
		res.push_back(tal);

		sht = 10000;
		rep(j, m) {
			tal = 0;
			rep(i, n) {
				if(hg[i][j] > tal) {
					tal = hg[i][j];
				}
			}
			if(tal < sht) {
				sht = tal;
			}
		}

		res.push_back(sht);

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"9 2 3",
 "4 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPeople(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2",
 "4 5",
 "3 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPeople(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 1",
 "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPeople(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TallPeople ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
