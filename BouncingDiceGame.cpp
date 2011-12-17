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

class BouncingDiceGame {
	public:
  int _n, _d;
    
  double f(int x, int y, int t, double mul) {
    double res = 0.0;
    
    if(x == _n) return mul;
    if(y == _n) return 0.0;
    if(mul < 1.0e-8) return 0.0;
    
    if(t) {
      repbe(i, 1, _d) {
        res += f(new_pos(x, i), y, !t, mul / _d);
      }
      return res;
    } else {
      repbe(i, 1, _d) {
        res += f(x, new_pos(y, i), !t, mul / _d);
      }
      return res;
    }
  }
    
  int new_pos(int x, int i) {
    if(x + i < _n) return x + i;
    return _n - (x + i - _n);
  }
    
	double winProbability(int n, int d, int x, int y) {
		double res;

		_n = n;
		_d = d;
		res = f(x, y, true, 1.0);

		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.5417251215862328; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.6090494791666666; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 20; int Arg2 = 1; int Arg3 = 10; double Arg4 = 0.49158887163174947; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 9; int Arg3 = 1; double Arg4 = 0.6943018666666667; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BouncingDiceGame __test;
	__test.run_test(-1);
	system("pause");
}
// END CUT HERE
