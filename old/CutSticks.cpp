#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

//]

// bool num_greater(int x, int y) { return x > y; }
bool num_greater(double x, double y) { return x > y; }

class CutSticks {
	public:
	double maxKth(vector <int> Sticks, int C, int K) {
		vector<double> sticks (Sticks.begin(), Sticks.end());
		sort(sticks.begin(), sticks.end(), num_greater);
		
		// for(unsigned int it = 0; it < sticks.size(); it++)
			// cout << sticks[it] << " ";
		// cout << endl;
			// printf("%i ", sticks[i]);
		
		while(sticks.size() < K) {
			C--;
			double d = sticks[0];
			sticks.erase(sticks.begin());
			// sticks.push_back(d / 2.);
				 // sticks.push_back(d / K);
				 sticks.push_back(d / C);
			// sticks.push_back(d / 2.);
				// sticks.push_back(d * (K - 1) / K);
				sticks.push_back(d * (C - 1) / C);
			sort(sticks.begin(), sticks.end(), num_greater);
			
		// for(unsigned int it = 0; it < sticks.size(); it++)
			// cout << sticks[it] << " ";
		// cout << endl;
		}
		
		// for(unsigned int i = 0; i < K - 1 && C; i++) {
		int i = 0;
			// while(sticks[i] / 2. > sticks[K - 1] && C) {
			// while(sticks[i] / K > sticks[K - 1] && C) {
			while(sticks[i] / C > sticks[K - 1] && C) {
				C--;
				double d = sticks[i];
				sticks.erase(sticks.begin() + i);
				// sticks.push_back(d / 2.);
				 // sticks.push_back(d / K);
				 sticks.push_back(d / C);
				// sticks.push_back(d / 2.);
				// sticks.push_back(d * (K - 1) / K);
				sticks.push_back(d * (C - 1) / C);
				sort(sticks.begin(), sticks.end(), num_greater);
		
		// cout << i << ": ";
		// for(unsigned int it = 0; it < sticks.size(); it++)
			// cout << sticks[it] << " ";
		// cout << endl;
			}
		// }
		
		return sticks[K - 1];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 8.0; verify_case(0, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 5.0; verify_case(1, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; double Arg3 = 4.0; verify_case(2, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; double Arg3 = 1.0; verify_case(3, Arg3, maxKth(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 789; int Arg2 = 456; double Arg3 = 34.92; verify_case(4, Arg3, maxKth(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CutSticks __test;
	__test.run_test(-1);
}
// END CUT HERE
