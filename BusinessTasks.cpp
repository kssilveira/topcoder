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

class BusinessTasks {
	public:
	string getTask(vector <string> list, int n) {
		int N = list.size();
		int k = 0;
		rep(i, N) {
			list.erase(list.begin() + ((k + n - 1) % (N - i)));
			k = (k + n - 1) % (N - i);
		}

		return list[0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "a"; verify_case(0, Arg2, getTask(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"a","b","c","d","e"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "d"; verify_case(1, Arg2, getTask(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"alpha","beta","gamma","delta","epsilon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "epsilon"; verify_case(2, Arg2, getTask(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; string Arg2 = "a"; verify_case(3, Arg2, getTask(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; string Arg2 = "n"; verify_case(4, Arg2, getTask(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
"olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
"qgcxjbfx","my","mlhy","bt","bo","q"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9000000; string Arg2 = "fxjqzznvg"; verify_case(5, Arg2, getTask(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	BusinessTasks ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
