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

class RobotSimulation {
	public:
	int cellsVisited(string program, int times) {
		int res;

		int i = 0, j = 0;
		set<pair<int, int> > s;
		s.insert(pair<int, int>(i, j));
		int n = program.size();
		int diff = 0;
		rep(x, times) {
			int last = s.size();
			rep(c, n) {
				switch(program[c]) {
					case 'U':
						i++;
						break;
					case 'D':
						i--;
						break;
					case 'L':
						j--;
						break;
					case 'R':
						j++;
						break;
				}
				s.insert(pair<int, int>(i, j));
			}
			//cout << "size: " << s.size() << " last: " << last << " diff: " << diff << " x: " << x << endl;
			if(s.size() - last == diff && x > 1000) {
				return s.size() + diff * (times - x - 1);
			}
			diff = s.size() - last;
			last = s.size();
		}

		return s.size();
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRR"; int Arg1 = 100; int Arg2 = 301; verify_case(0, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "DDU"; int Arg1 = 100; int Arg2 = 102; verify_case(1, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "URLD"; int Arg1 = 100; int Arg2 = 3; verify_case(2, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "UUDUDDLLDR"; int Arg1 = 1; int Arg2 = 7; verify_case(3, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "UUDUDDLLDR"; int Arg1 = 12345678; int Arg2 = 37037039; verify_case(4, Arg2, cellsVisited(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "RRUUULLDD"; int Arg1 = 3603602; int Arg2 = 10810815; verify_case(5, Arg2, cellsVisited(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RobotSimulation ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
