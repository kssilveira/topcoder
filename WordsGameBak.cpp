#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WordsGame {
	public:
	int minimumSwaps(vector <string> grid, string word) {
		int n = word.size(), res = -1, tmp;
		for(int line = 0; line < n; line++) {
			tmp = solve(grid[line].c_str(), word.c_str());
			if(tmp != -1 && (tmp < res || res == -1))
				res = tmp;
		}
		for(int col = 0; col < n; col++) {
			string arg;
			for(int line = 0; line < n; line++) {
				char s[2] = {0};
				s[0] = grid[line][col];
				arg.append(s);
			}
			tmp = solve(arg.c_str(), word.c_str());
			if(tmp != -1 && (tmp < res || res == -1))
				res = tmp;
		}
		return res;
	}

	int solve(const char *rs, const char *t) {
		cout << "solve(" << rs << ", " << t << ")" << endl;
		char s[52];
		strcpy(s, rs);
		int res = 0, cur;
		for(cur = 0; t[cur]; cur++) {
			int i;
			for(i = cur; s[i]; i++)
				if(s[i] == t[cur])
					break;
			if(!s[i])
				break;
			if(i != cur) {
				char tmp = s[i];
				s[i] = s[cur];
				s[cur] = tmp;
				res++;
			}
		}
		if(t[cur])
			return -1;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Mu",
 "uM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Mu"; int Arg2 = 0; verify_case(0, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"sdf",
 "bca",
 "hgf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 2; verify_case(1, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cdf",
 "bca",
 "agf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 1; verify_case(2, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bkHg"; int Arg2 = 2; verify_case(3, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "oDmWcJHGNk"; int Arg2 = 6; verify_case(4, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aB"; int Arg2 = -1; verify_case(5, Arg2, minimumSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WordsGame __test;
	__test.run_test(-1);
}
// END CUT HERE
