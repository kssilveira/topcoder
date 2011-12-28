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

int v[60][60];

class CondorcetVoting {
	public:
	int winner(vector <string> votes) {
		int res = 0;
		int n = votes.size();
		int m = votes[0].size();
		memset(v, 0, sizeof(v));
		rep(i, n) {
			rep(j, m) {
				repb(k, j + 1, m) {
					v[j][k] += votes[i][j] < votes[i][k];
					v[k][j] += votes[i][j] > votes[i][k];
				}
			}
		}

		res = -1;
		rep(i, m) {
			bool found = false;
			rep(j, m) {
				if(v[i][j] <= v[j][i] && i != j) {
					found = true;
					break;
				}
			}
			if(!found) {
				res = i;
				break;
			}
		}
		

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acbd",
 "bacd",
 "bdca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arr0[] = {"abc", 
 "bca", 
 "cab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arr0[] = {"cezdqcw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arr0[] = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd",
 "cbad", "cbad", "cbad", "cbad", "cbad",
 "dbca", "cbda", "cbda"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { string Arr0[] = {"abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac",
 "accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc",
 "acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb",
 "acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba",
 "cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb",
 "cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca",
 "cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa",
 "bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab",
 "bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac",
 "accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac",
 "cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb",
 "bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca",
 "cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc",
 "baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba",
 "bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb",
 "cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab",
 "bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac",
 "aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb",
 "bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb",
 "bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc",
 "bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba",
 "aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc",
 "abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb",
 "cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca",
 "babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca",
 "cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa",
 "aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba",
 "caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba",
 "bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab",
 "bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa",
 "bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb",
 "bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba",
 "abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca",
 "acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca",
 "aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb",
 "ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab",
 "bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc",
 "abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac",
 "bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb",
 "cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb",
 "bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb",
 "abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa",
 "bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc",
 "babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc",
 "cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa",
 "caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba",
 "cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb",
 "ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab",
 "abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb",
 "bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, winner(Arg0)); }
	void test_case_5() { string Arr0[] = {"h", "e", "l", "l", "o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, winner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	CondorcetVoting ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
