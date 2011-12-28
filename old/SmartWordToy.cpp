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

string forbids[51][4];

class SmartWordToy {
	public:
		int n;
	bool isvalid(string s) {
		return true;
		rep(i, n) {
			rep(j, 4) {
				bool found = false;
				rep(k, (int) forbids[i][j].size()) {
					if(s[j] == forbids[i][j][k]) {
						found = true;
						break;
					}
				}
				if(!found) {
					j = 10;
				}
				if(found && j == 3) {
					return false;
				}
			}
		}
		return true;
	}

	int minPresses(string start, string finish, vector <string> forbid) {
		int res = -1;

		// LARGUEI DE MÃO!!!
		
		set<int> went;
		n = forbid.size();
		rep(i, (int) forbid.size()) {
			char sa[100], sb[100], sc[100], sd[100];
			sscanf(forbid[i].c_str(), "%s %s %s %s", sa, sb, sc, sd);
			forbids[i][0] = sa;
			forbids[i][1] = sb;
			forbids[i][2] = sc;
			forbids[i][3] = sd;
			//cout << "ss: " << sa << "+" << sb << "+" << sc << "+" << sd << endl;
			
			rep(i, strlen(sa)) {
				rep(j, strlen(sb)) {
					rep(k, strlen(sc)) {
						rep(l, strlen(sd)) {
							//went.insert(string("") + sa[i] + sb[j] + sc[k] + sd[l]);
							went.insert((((sa[i] - 'a') * 10 + sb[j] - 'a') * 10 + sc[k] - 'a') * 10 + sd[l] - 'a');
						}
					}
				}
			}
		}

		if(!isvalid(finish)) return -1;

		queue<pair<int, int> > q;
		int Start = (((start[0] - 'a') * 10 + start[i] - 'a') * 10 + start[2] - 'a') * 10 + start[3] - 'a';
		q.push(make_pair(Start, 0));
		went.insert(start);
		while(!q.empty()) {
			int cur = q.front().first;
			int dist = q.front().second;
			//cout << "cur: " << cur << " dist: " << dist << endl;
			q.pop();
			if(cur == finish) return dist;
			rep(i, 4) {
				int s = string(cur);
				s[i]++;
				if(s[i] > 'z') s[i] = 'a';
				if(isvalid(s) && went.insert(s).second) {
					q.push(make_pair(s, dist + 1));
				}
				s[i] = cur[i] - 1;
				if(s[i] < 'a') s[i] = 'z';
				if(isvalid(s) && went.insert(s).second) {
					q.push(make_pair(s, dist + 1));
				}
			}
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "mmnn"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; verify_case(2, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"bz a a a", "a bz a a", "a a bz a", "a a a bz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"cdefghijklmnopqrstuvwxyz a a a", 
 "a cdefghijklmnopqrstuvwxyz a a", 
 "a a cdefghijklmnopqrstuvwxyz a", 
 "a a a cdefghijklmnopqrstuvwxyz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(4, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {"b b b b"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(5, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "zzzz"; string Arg1 = "aaaa"; string Arr2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minPresses(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	SmartWordToy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
