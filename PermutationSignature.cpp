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
 
#define SIZE 60
class PermutationSignature {
	public:
	vector <int> reconstruct(string signature) {
		int n = (int) signature.size();
		vector <int> res(n + 1);
		int cnt[SIZE] = {0};
 
		res[0] = 1;
		cnt[1] = 1;

		for(int i = 1; i <= n; i++) {

			/*
			for(int j = 0; j < i; j++) {
				cout << res[j] << " ";
			}
			cout << endl;//*/

			char cur = signature[i - 1];
			if(cur == 'I') {
				bool found = false;
				for(int j = res[i - 1] + 1; j <= n + 1; j++) {
					if(cnt[j] == 0) {
						res[i] = j;
						cnt[j] = 1;
						found = true;
						break;
					}
				}
				if(!found) {
					return vector<int>();
				}
			} else {
				res[i] = res[i - 1];
				cnt[res[i]]++;

				for(int j = i - 1; j >= 0; j--) {

					cnt[res[j]]--;
					if(j > 0 && signature[j - 1] == 'D') {
						res[j] = res[j - 1];
						cnt[res[j]]++;
						continue;
					}

					bool found = false;
					for(int k = res[j + 1] + 1; k <= n + 1; k++) {
						if(cnt[k] == 0) {
							res[j] = k;
							cnt[k] = 1;
							found = true;
							break;
						}
					}
					if(!found) {
						return vector<int>();
					}

					if(j > 0 && signature[j - 1] == 'I') break;
				}
			}
		}
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "DI"; int Arr1[] = {2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "DIIDID"; int Arr1[] = {2, 1, 3, 5, 4, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	PermutationSignature ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
