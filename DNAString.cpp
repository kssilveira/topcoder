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

int toNum(char c)
{
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'T') return 2;
	if(c == 'G') return 3;
	exit(1);
}

#define SIZE (50 * 50 + 10)

int solve(string s, int period)
{
	int cnt[SIZE][4] = {{0}},
			nmax[SIZE] = {0},
			total[SIZE] = {0};

	for(int i = 0; i < (int) s.size(); i++) {
		cnt[i % period][toNum(s[i])]++;
		total[i % period]++;
		nmax[i % period] = max(nmax[i % period],
				cnt[i % period][toNum(s[i])]);
	}

	int res = 0;
	for(int i = 0; i < period; i++) {
		res += total[i] - nmax[i];
	}

	return res;
}
 
class DNAString {
	public:
	int minChanges(int maxPeriod, vector <string> dna) {
		int res = 50 * 50 * 50 + 1;
		string s;
		for(int i = 0; i < (int) dna.size(); i++) {
			s += dna[i];
		}

		for(int i = 1; i <= maxPeriod; i++) {
			int sol = solve(s, i);
			if(sol < res) {
				res = sol;
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
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"ATAGATA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minChanges(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"ACGTGCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minChanges(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; string Arr1[] = {"ACGCTGACAGATA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minChanges(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; string Arr1[] = {"AAAATTTCCG"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, minChanges(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; string Arr1[] = {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(4, Arg2, minChanges(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	DNAString ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
