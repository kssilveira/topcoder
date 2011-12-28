#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) reptbc(int, i, b, n, c)
#define reps(i, n) repbs(i, 0, n)
#define repbs(i, b, n) reptbc(unsigned int, i, b, n.size(), <)
#define reptbc(t, i, b, n, c) for(t i = b; i c n; i++)

using namespace std;

class BunnyPuzzle {
	public:
	int theCount(vector <int> bunnies) {
    int res = 0;
    
    v = bunnies;
    
    repbs(i, 1, v) {
      if(canJump(v[i], v[i - 1])) res++;
      if(canJump(v[i - 1], v[i])) res++;
    }
    
		return res;
	}
	
	int jump(int a, int b) { return 2 * b - a; }
	bool canJump(int a, int b) {
    reps(i, v) {
      if( (b < v[i] && v[i] <= jump(a, b)) ||
          (b > v[i] && v[i] >= jump(a, b)) ||
          (a > v[i] && v[i] > b) ||
          (a < v[i] && v[i] < b)
        )
        return false;
    }
    return true;
  }

  vector<int> v;
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-677, -45, -2, 3, 8, 29, 384, 867}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main() {
	BunnyPuzzle __test;
	__test.run_test(-1);
	system("pause");
}
// END CUT HERE
