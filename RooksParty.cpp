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


int temp;
const int MODULO = 1000000009;

class RooksParty {
	public:
	vector <int> counts;
	int rows;
	int columns;
	int line[31];
	int col[31];
	int countArrangements(int rows, int columns, vector <int> counts) {
		int res = 0;

		this->rows = rows;
		this->columns = columns;
		this->counts = counts;

		memset(line, -1, sizeof(line));
		memset(col, -1, sizeof(col));

		return count(0, 0, 0, 0);
	}

	int count(int cur, int curcount, int bx, int by) {
		if(curcount == counts[cur]) {
			if(cur == counts.size() - 1) {
				//printf("end!\n");
				return 1;
			} else {
				return count(cur + 1, 0, 0, 0);
			}
		}

		int res = 0;
		repb(i, bx, rows) {
			repb(j, by, columns) {
				if(line[i] < 0 || line[i] == cur) {
					if(col[j] < 0 || col[j] == cur) {
						int tline = line[i],
								tcol = col[j];
						line[i] = cur;
						col[j] = cur;
						//printf("t: %i %i\n", tline, tcol);
						//printf("(%i, %i): %i\n", i, j, cur);
						res += count(cur, curcount + 1, i, j + 1);
						res %= MODULO;
						line[i] = tline;
						col[j] = tcol;
					}
				}
			}
			by = 0;
		}
		return res % MODULO;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(0, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(1, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 8; int Arr2[] = {1,1,1,1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 625702391; verify_case(3, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, countArrangements(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	RooksParty ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
