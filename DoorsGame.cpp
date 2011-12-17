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
 
class DoorsGame {
	public:
		int t, n;
		string door;

	int determineOutcome(string doors, int trophy) {
		int res;
		this->t = trophy;
		this->n = doors.size();
		this->door = doors;
		set<int> Set[2];
		vector<int> v(20);

		rep(i, n)
			doors[i] -= 'A';

		//rep(i, n) printf("%i ", doors[i]);
		//printf("\n");

		rep(i, t)
			Set[0].insert(door[i]);
		repb(i, t, n)
			Set[1].insert(door[i]);

		vector<int>::iterator it;
		it = set_intersection(Set[0].begin(), Set[0].end(),
				Set[1].begin(), Set[1].end(), v.begin());
		//printf("inter: %i\n", int(it - v.begin()));
		int inter = it - v.begin();

		if((Set[0].size() == Set[1].size() || Set[0].size() == Set[1].size() + 1) && inter > 0) return 0;
		if(Set[0].size() <= Set[1].size()) return min((int) (2 * Set[0].size() - 1), 15);
		return -min((int) (2 * Set[1].size()), 16);
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCC"; int Arg1 = 2; int Arg2 = -2; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABABAB"; int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABAPDCAA"; int Arg1 = 5; int Arg2 = -4; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "MOCFDCE"; int Arg1 = 3; int Arg2 = 5; verify_case(4, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ABCCDE"; int Arg1 = 3; int Arg2 = 0; verify_case(5, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABCCD"; int Arg1 = 3; int Arg2 = 0; verify_case(6, Arg2, determineOutcome(Arg0, Arg1)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	DoorsGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
