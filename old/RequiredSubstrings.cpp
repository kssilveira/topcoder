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

int countbits(int mask) {
  int res = 0;
  while (mask > 0) {
    if (mask & 1) res++;
    mask >>= 1;
  }
  return res;
}
 
class RequiredSubstrings {
	public:
	int solve(vector <string> Words, int C, int L) {
		int res = 0;
    int n = (int) Words.size();

    for (int mask = 0; mask < (1 << n); mask++) {
      if (countbits(mask) != C) continue;
      // cout << "mask: " << mask << endl;
      int perm[6] = {0, 1, 2, 3, 4, 5};
      vector<string> words;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          words.push_back(Words[i]);
        }
      }
      do {
        // rep(i, C) cout << perm[i] << " ";
        // cout << endl;
        string s;
        if (C != 0) {
          s = words[perm[0]];
        }
        for (int i = 1; i < C; i++) {
          bool added = false;
          for (int j = 0; j < (int) s.length(); j++) {
            bool found = false;
            for (int k = j; k < (int) s.length(); k++) {
              if (s[k] != words[perm[i]][k - j]) {
                found = true;
                break;
              }
            }
            if (!found) {
              added = true;
              s = s.substr(0, j) + words[perm[i]];
              // cout << "s: " << s << endl;
              break;
            }
          }
          if (!added) {
            s += words[perm[i]];
            // cout << "s2: " << s << endl;
          }
        }

        int slen = (int) s.length();
        if (slen > L) continue;

        cout << "s: " << s << endl;

        for (int left = 0; left + slen <= L; left++) {
          int right = slen - left;
          for (int i = 0; i < n; i++) {
            if (Words[i].substr(left, slen) == s &&
                !(mask & (1 << i)) &&
                (int) Words[i].length() <= L) {
              cout << "left: " << left << " invalid: " << Words[i] << endl;
            }
          }
        }

      } while (next_permutation(perm, perm + C));
    }
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","aa","aaa","aaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 50; verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 7; int Arg3 = 31810104; verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"abcdefgh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; int Arg3 = 0; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 24; verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ab","bc","xy","yz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 2; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RequiredSubstrings ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
