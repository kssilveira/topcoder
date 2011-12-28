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
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)
 
#define s(v) ((int) v.size())
 
using namespace std;
 
class GymTraining {
	public:
	int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange) {
		int res = 0;

    if (minPulse + trainChange > maxPulse) return -1;
 
    int curPulse = minPulse;
    r(i, needToTrain) {
      while (curPulse + trainChange > maxPulse) {
        curPulse = max(curPulse - restChange, minPulse);
        res++;
      }
      curPulse += trainChange;
      res++;
    }
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 70; int Arg2 = 120; int Arg3 = 25; int Arg4 = 15; int Arg5 = 10; verify_case(0, Arg5, trainingTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 50; int Arg2 = 100; int Arg3 = 5; int Arg4 = 200; int Arg5 = 109; verify_case(1, Arg5, trainingTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 60; int Arg2 = 70; int Arg3 = 11; int Arg4 = 11; int Arg5 = -1; verify_case(2, Arg5, trainingTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 50; int Arg2 = 200; int Arg3 = 150; int Arg4 = 1; int Arg5 = 30050; verify_case(3, Arg5, trainingTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 19; int Arg1 = 89; int Arg2 = 143; int Arg3 = 17; int Arg4 = 13; int Arg5 = 40; verify_case(4, Arg5, trainingTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	GymTraining ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
