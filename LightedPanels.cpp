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
int board[10][10];

class Board {
public:
	Board(int b[10][10], int on, int mv) {
		this->on = on;
		this->mv = mv;
		memcpy(board, b, sizeof(b));
	}
	Board(const Board& r) {
		this->on = r.on;
		this->mv = r.mv;
		memcpy(board, r.board, sizeof(board));
	}
	Board(Board * r) {
		this->on = r->on;
		this->mv = r->mv;
		memcpy(board, r->board, sizeof(board));
	}
	bool operator<(const Board& r) const {
		if(on < r.on) return true;
		if(on > r.on) return false;
		if(mv < r.mv) return true;
		if(mv > r.mv) return false;
		repb(i, 1, 10)
			repb(j, 1, 10) {
				if(board[i][j] < r.board[i][j]) return true;
				if(board[i][j] > r.board[i][j]) return false;
			}

		return false;
	}
	int on, mv, board[10][10];
};
 
class LightedPanels {
	public:
	int minTouch(vector <string> sboard) {
		int n = (int)sboard.size(),
				m = (int)sboard[0].size();
		memset(board, 0, sizeof(board));
		int on = 0;
		rep(i, n) {
			rep(j, m) {
				board[i + 1][j + 1] = sboard[i][j] == '*';
				on += board[i + 1][j + 1];
			}
		}

		//*
		printf("on: %i\n", on);
		rep(i, n + 2) {
			rep(j, m + 2) {
				printf("%i", board[i][j]);
			}
			printf("\n");
		}
		printf("\n");//*/
 
		priority_queue<Board *> q;
		set<Board *> s;
		q.push(new Board(board, on, 0));
		while(!q.empty()) {
			Board *b = q.top();

		//*
		printf("on: %i\n", b->on);
		printf("mv: %i\n", b->mv);
		rep(i, n + 2) {
			rep(j, m + 2) {
				printf("%i", b->board[i][j]);
			}
			printf("\n");
		}
		printf("\n");//*/
 
			q.pop();
			if(!s.insert(new Board(b)).second) continue;
			repb(i, 1, 10) {
				repb(j, 1, 10) {
					Board nb(b);
					int non = on;
					static int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
					rep(d, 9) {
						nb.board[i + dir[d][0]][j + dir[d][1]] = !nb.board[i + dir[d][0]][j + dir[d][1]];
						if(nb.board[i + dir[d][0]][j + dir[d][1]]) {
							non++;
						}
					}
					nb.on = non;
					nb.mv++;
					if(nb.on == n * m) {
						return nb.mv;
					}
					q.push(new Board(nb));
				}
			}
			delete b;
		}
 
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*****",
 "*...*",
 "*...*",
 "*...*",
 "*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minTouch(Arg0)); }
	void test_case_1() { string Arr0[] = {".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTouch(Arg0)); }
	void test_case_2() { string Arr0[] = {"**.",
 "**.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minTouch(Arg0)); }
	void test_case_3() { string Arr0[] = {"*...",
 "**..",
 "..**",
 "...*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minTouch(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	LightedPanels ___test; 
	___test.run_test(1); 
} 
// END CUT HERE
