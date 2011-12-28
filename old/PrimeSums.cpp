#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

bool isPrime[500010];
long long myCount[2][500010];

class PrimeSums {
	public:
		long long getCount(vector <int> bag) {
			long long res = 0;

			sort(bag.begin(), bag.end());

			int sum = 0;
			for(int i = 0; i < bag.size(); i++)
				sum += bag[i];

			memset(isPrime, true, sizeof(isPrime));

			isPrime[0] = isPrime[1] = false;

			for(int i = 2; i * i <= sum; i++)
				if(isPrime[i]) {
					//cout << i << "is prime" << endl;
					for(int j = i * i; j <= sum; j += i)
						isPrime[j] = false;
				}

			memset(myCount, 0, sizeof(myCount));
			myCount[0][0] = 1;

			int next = 1, last = 0;
				for(int i = 0; i < bag.size(); i++) {
					if(i > 0 && bag[i] == bag[i - 1]) continue;
					int cnt = 1;
					for(int j = i + 1; j < bag.size() && bag[j] == bag[i]; j++, cnt++);
					//cout << i << ' ' << bag[i] << ' ' << cnt << endl;
			for(int w = 0; w <= sum; w++) {
					myCount[next][w] = myCount[last][w];
					for(int j = 1; j <= cnt; j++)
						if(bag[i] * j <= w)
							myCount[next][w] += myCount[last][w - bag[i] * j];
			}
					next = 1 - next;
					last = 1 - last;
				}


			for(int i = 2; i <= sum; i++)
				if(isPrime[i])
					res += myCount[last][i];


			return res;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1,1,2,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(0, Arg1, getCount(Arg0)); }
		void test_case_1() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(1, Arg1, getCount(Arg0)); }
		void test_case_2() { int Arr0[] = {4,6,8,10,12,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, getCount(Arg0)); }
		void test_case_3() { int Arr0[] = {1,2,4,8,16,32,64,128}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 54LL; verify_case(3, Arg1, getCount(Arg0)); }
		void test_case_4() { int Arr0[] = {1234,5678,9012,3456,7890,2345,6789,123,4567,8901}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 97LL; verify_case(4, Arg1, getCount(Arg0)); }
		void test_case_5() { int Arr0[] = {0,0,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(5, Arg1, getCount(Arg0)); }

		// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	PrimeSums ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
