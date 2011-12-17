#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define PAR(x) ((x) % 2 == 0)

class SilverDistance {
	public:
	int minSteps(int sx, int sy, int gx, int gy) {
		if(sx == gx && sy == gy)
			return 0;
		if(sx == gx && sy < gy)
			return gy - sy;
		if(sx == gx && sy > gy) {
			if(PAR(sy - gy))
				return sy - gy;
			else return sy - gy + 2;
		}
		if(sx < gx && sy == gy) {
			if(PAR(gx - sx))
				return gx - sx;
			else return gx - sx + 1;
		}
		if(sx > gx && sy == gy) {
			if(PAR(sx - gx))
				return sx - gx;
			else return sx - gx + 1;
		}
		if(sx < gx && sy < gy) {
			if(gx - sx < gy - sy)
				return gx - sx + minSteps(gx, sy + gx - sx, gx, gy);
			else return gy - sy + minSteps(sx + gy - sy, gy, gx, gy);
		}
		if(sx < gx && sy > gy)  {
			if(gx - sx < sy - gy)
				return gx - sx + minSteps(gx, sy - (gx - sx), gx, gy);
			else return sy - gy + minSteps(sx + sy - gy, gy, gx, gy);
		}
		if(sx > gx && sy < gy) {
			if(sx - gx < gy - sy)
				return sx - gx + minSteps(gx, sy + sx - gx, gx, gy);
			else return gy - sy + minSteps(sx - (gy - sy), gy, gx, gy);
		}
		if(sx > gx && sy > gy) {
			if(sx - gx < sy - gy)
				return sx - gx + minSteps(gx, sy - (sx - gx), gx, gy);
			else return sy - gy + minSteps(sx - (sy - gy), gy, gx, gy);
		}
		printf("erro");
		return 0;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 9; int Arg4 = 9; verify_case(0, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = -4; int Arg3 = 3; int Arg4 = 5; verify_case(1, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 5; int Arg3 = 8; int Arg4 = 8; verify_case(2, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = -487617; int Arg1 = 826524; int Arg2 = 892309; int Arg3 = -918045; int Arg4 = 1744571; verify_case(3, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = -27857; int Arg1 = 31475; int Arg2 = -27857; int Arg3 = 31475; int Arg4 = 0; verify_case(4, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 3; int Arg3 = 0; int Arg4 = 4; verify_case(5, Arg4, minSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SilverDistance __test;
	__test.run_test(-1);
}
// END CUT HERE
