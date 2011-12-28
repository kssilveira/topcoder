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

class WordForm {
	public:
		
	string word;
	bool isvowel(int i) {
		switch(toupper(word[i])) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				return true;
			case 'Y':
				return i != 0 && !isvowel(i - 1);
			default:
				return false;
		}
		return false;
	}

	string getSequence(string word) {
		string res;

		int n = word.size();

		this->word = word;
		int cur = -1;
		rep(i, n) {
			if(isvowel(i) && cur != 0) {
				res.push_back('V');
				cur = 0;
			}
			if(!isvowel(i) && cur != 1) {
				res.push_back('C');
				cur = 1;
			}
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WHEREABOUTS"; string Arg1 = "CVCVCVC"; verify_case(0, Arg1, getSequence(Arg0)); }
	void test_case_1() { string Arg0 = "yoghurt"; string Arg1 = "CVCVC"; verify_case(1, Arg1, getSequence(Arg0)); }
	void test_case_2() { string Arg0 = "YipPy"; string Arg1 = "CVCV"; verify_case(2, Arg1, getSequence(Arg0)); }
	void test_case_3() { string Arg0 = "AyYyEYye"; string Arg1 = "VCVCVCV"; verify_case(3, Arg1, getSequence(Arg0)); }
	void test_case_4() { string Arg0 = "yC"; string Arg1 = "C"; verify_case(4, Arg1, getSequence(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	WordForm ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
