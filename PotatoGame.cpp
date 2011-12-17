#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cstring>
#include <climits>
#include <bitset>
#include <cassert>

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

#define MAX_SIZE 100000
#define N_POWS 15

static bitset<MAX_SIZE + 1> r;
int pow[N_POWS] = {268435456, 67108864, 16777216, 4194304, 1048576, 262144, 65536, 16384, 4096, 1024, 256, 64, 16, 4, 1};

bool f(int x)
{
	//if(x < MAX_SIZE) return r[x];
	int n = x, s = 0;
	while(n) {
		s++;
		n /= 4;
	}
	//printf("(n, s): %i %i\n", n, s);
	if(n % 2) return true;
	rep(p, N_POWS) {
		if(pow[p] > x) continue;
		if(!f(x - pow[p])) {
			return true;
		}
	}
	return false;
}

int d[] = {0, 1, 0, 0, 1, 0, 1, 0, 0, 1};

int g(int n) {
	return !d[(n - 1) % 10];
}

class PotatoGame {
	public:
	string theWinner(int n) {
		return n % 5 & 5 ? "Taro" : "Hanako";
		string res;

		//memset(r, 0, sizeof(r));
		
		//for(int i =  268435456; i >= 1; i /= 4) {
			//printf("%i, ", i);
		//}

		r[0] = 0;
		r[1] = 1;
		r[2] = 0;
		r[3] = 1;
		r[4] = 1;
		repbe(i, 5, MAX_SIZE + 0 * min(n, MAX_SIZE)) {
			bool found = false;
			rep(p, N_POWS) {
				if(pow[p] > i) continue;
				if(!r[i - pow[p]]) {
					found = true;
					break;
				}
			}
			r[i] = found;
			//printf("r[%i]: %i\n", i, r[i]);
			//assert(r[i] == f(i));
			assert(r[i] == g(i));
			cout << "r[" << i << "]: " << r[i] << endl;
		}
				
		res = f(n) ? "Taro" : "Hanako";

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "Taro"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "Hanako"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "Taro"; verify_case(2, Arg1, theWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	PotatoGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
