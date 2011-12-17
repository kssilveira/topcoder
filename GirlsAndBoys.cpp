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

class GirlsAndBoys {
	public:
	int sortThem(string row) {
		string realrow = row;
		int res = 0;
		int n = (int) row.size();
		int found = 0;
		int nb = 0, ng = 0;

		if(n == 1) return 0;

		rep(i, n) {
			if(row[i] == 'G') ng++;
			else if(row[i] == 'B') nb++;
		}

		if(ng == 0 || nb == 0) return 0;

		repb(i, 1, n)
			for(int j = i; j >= 1; j--)
				if(row[j] < row[j - 1]) {
					//cout << "row i: " << row << endl;
					swap(row[j], row[j - 1]);
					res++;
				}

		int realres = res;
		//cout << "row: " << row << " real_res: " << realres << endl;

		row = realrow;
		res = 0;
		repb(i, 1, n)
			for(int j = i; j >= 1; j--)
				if(row[j] > row[j - 1]) {
					swap(row[j], row[j - 1]);
					res++;
				}

		if(realres > res) realres = res;
		//cout << "row: " << row << " real_res: " << realres << endl;

		row = realrow;
		res = 0;
		for(int i = n - 1; i >= 0; i--)
			for(int j = i; j < n - 1; j++)
				if(row[j] < row[j + 1]) {
					swap(row[j], row[j + 1]);
					res++;
				}

		if(realres > res) realres = res;
		//cout << "row: " << row << " real_res: " << realres << endl;

		row = realrow;
		res = 0;
		for(int i = n - 1; i >= 0; i--)
			for(int j = i; j < n - 1; j++)
				if(row[j] > row[j + 1]) {
					swap(row[j], row[j + 1]);
					res++;
				}

		if(realres > res) realres = res;
		//cout << "row: " << row << " real_res: " << realres << endl;

		return realres;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "GGBBG"; int Arg1 = 2; verify_case(0, Arg1, sortThem(Arg0)); }
	void test_case_1() { string Arg0 = "BBBBGGGG"; int Arg1 = 0; verify_case(1, Arg1, sortThem(Arg0)); }
	void test_case_2() { string Arg0 = "BGBGBGBGGGBBGBGBGG"; int Arg1 = 33; verify_case(2, Arg1, sortThem(Arg0)); }
	void test_case_3() { string Arg0 = "B"; int Arg1 = 0; verify_case(3, Arg1, sortThem(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	GirlsAndBoys ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
