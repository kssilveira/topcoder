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

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

char trans(char c)
{
	switch(c) {
		case 'A':
			return 'T';
		case 'T':
			return 'A';
		case 'C':
			return 'G';
		case 'G':
			return 'C';
	}
	return 'X';
}

bool isEqu(string a, string b)
{
	if(a.size() != b.size()) return false;
	rep(i, a.size())
		if(a[i] != trans(b[a.size() - i - 1])) return false;
	return true;
}

class DNAMatching {
	public:
	int getMaxSize(vector <string> dna) {
		int res = dna.size();

		rep(i, dna.size())
			repb(j, i + 1, dna.size())
				if(isEqu(dna[i], dna[j]))
					res--;
		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ACGCGCGTA", "GTCGATGCA", "ACGTAGCT", "TACGCGCGT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMaxSize(Arg0)); }
	void test_case_1() { string Arr0[] = {"A","C","T","G"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMaxSize(Arg0)); }
	void test_case_2() { string Arr0[] = {"ATTA", "ATCG", "CGAT", "ATCGCGAT", "CCCGGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getMaxSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	DNAMatching ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
