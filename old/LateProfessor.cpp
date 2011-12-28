#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class LateProfessor {
	public:
	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
		double res;
		long long num = 0;

		int begin = bestArrival % (waitTime + walkTime);
		int end = worstArrival % (waitTime + walkTime);

		cout << "begin: " << begin << endl;
		cout << "end: " << end << endl;

		if(begin <= waitTime) {
			num += walkTime - lateTime;
			cout << "1" << endl;
		} else if(waitTime + walkTime - begin >= lateTime) {
			num += waitTime + walkTime - begin - lateTime;
			cout << "2" << endl;
		}

		cout << "num: " << num << endl;

		if(end <= waitTime) {
		} else if(waitTime + walkTime - end >= lateTime) {
			cout << "3" << endl;
			num += waitTime + walkTime - end - lateTime;
		}
		
		cout << "num: " << num << endl;

		num += ((long long)(walkTime - lateTime)) * ((long long) (worstArrival - bestArrival - (waitTime + walkTime - begin) - end)) / (long long) (walkTime + waitTime);
		
		if(walkTime <= lateTime) return 0;
		if(worstArrival == bestArrival) {
			if(num) return 1;
			return 0;
		}

		res = num / (double) (worstArrival - bestArrival);

		return res;
/*
		if(begin <= waitTime) {
			if(end <= waitTime) {
				res = (walkTime - lateTime) / (double) (waitTime + walkTime);
		cout << "res: " << res << endl;
				res *= (worstArrival - bestArrival) / (double) (waitTime + walkTime);
		cout << "res: " << res << endl;
			} else {
				res = ((walkTime - lateTime) * (worstArrival - bestArrival - end) + min 
		cout << "res1: " << res << endl;
			}
		} else {
			if(end <= waitTime) {
				
			
		cout << "res2: " << res << endl;
			} else {
		cout << "res3: " << res << endl;
			}
		}//*/

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 0; int Arg4 = 50; double Arg5 = 0.4; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 30; int Arg4 = 100; double Arg5 = 0.42857142857142855; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arg2 = 50; int Arg3 = 0; int Arg4 = 300; double Arg5 = 0.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 101; int Arg1 = 230; int Arg2 = 10; int Arg3 = 654; int Arg4 = 17890; double Arg5 = 0.6637270828498492; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 90; int Arg4 = 90; double Arg5 = 1.0; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 600; int Arg2 = 1; int Arg3 = 17000; int Arg4 = 17000; double Arg5 = 0.0; verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	LateProfessor ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
