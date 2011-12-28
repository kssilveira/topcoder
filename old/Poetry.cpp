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

class Poetry {
	public:
	string rhymeScheme(vector <string> poem) {
		string res;

		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"I hope this problem",
 "is a whole lot better than",
 "this stupid haiku"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; verify_case(0, Arg1, rhymeScheme(Arg0)); }
	void test_case_1() { string Arr0[] = {"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = " aab ccde"; verify_case(1, Arg1, rhymeScheme(Arg0)); }
	void test_case_2() { string Arr0[] = {"One bright day in the middle of the night",
 "Two dead boys got up to fight",
 "Back to back they faced each other",
 "Drew their swords and shot each other",
 "",
 "A deaf policeman heard the noise",
 "And came to arrest the two dead boys",
 "And if you dont believe this lie is true",
 "Ask the blind man he saw it too"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aabb cdef"; verify_case(2, Arg1, rhymeScheme(Arg0)); }
	void test_case_3() { string Arr0[] = {"",
 "",
 "",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "    "; verify_case(3, Arg1, rhymeScheme(Arg0)); }
	void test_case_4() { string Arr0[] = {"This poem has uppercase letters",
 "In its rhyme scheme",
 "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", 
 "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
 "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
 "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
 "oval", "cable", "rob", "steal", "steel", "weak"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcdefghibjkblmnopqrstcuvwxyzABCbDEFG"; verify_case(4, Arg1, rhymeScheme(Arg0)); }
	void test_case_5() { string Arr0[] = {" ",
 "     ",
 "This poem",
 "         ",
 " ",
 " ",
 "",
 "Has lots of blank lines",
 " ",
 "      ",
 "                                            ",
 "         ",
 " ",
 "              ",
 "                                                  ",
 "  in      it           "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "  a    b       c"; verify_case(5, Arg1, rhymeScheme(Arg0)); }
	void test_case_6() { string Arr0[] = {"too bad   your",
 "     solution went   sour"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa"; verify_case(6, Arg1, rhymeScheme(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	Poetry ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
