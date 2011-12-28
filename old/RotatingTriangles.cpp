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

int toTab(char c) {
	if(c == '.') return 0;
	if(c == '#') return 1;
	if(c == '/') return 2;
	return -1;
}

		int tab[60][60] = {{0}};
int test(int bx, int by, int cx, int cy) {
	int res = 0;
	static int dir[][2] = {
		{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	if(bx == cx && by == cy) {
		rep(d, 4) {
			int nx = bx + dir[d][0],
					ny = by + dir[d][1],
					nnx = bx + dir[(d + 1) % 4][0],
					nny = by + dir[(d + 1) % 4][1];
			if(!(tab[nx][ny] % 2) && !(tab[nnx][nny] % 2)) {
				res++;
			}
		}
	} else {
		int sx = cx - bx + 1;
		int sy = cy - by + 1;
		bool good[2] = {true, true};
		repbe(i, sx) {
			repbe(j, sy) {
				if(i == j) {
					if(tab[bx + i][by + j] != 1) {
						good[0] = good[1] = false;
					}
				}
				if(i > j) {
					if(tab[bx + i][by + j] == 0) {
						good[0] = false;
					}
				}
				if(i < j) {
					if(tab[bx + i][by + j] == 0) {
						good[1] = false;
					}
				}
			}
		}
		if(good[0]) {
			rep(i, sx) {
				if(tab[i + bx][by - 1] == 2) {
					good[0] = false;
					break;
				}
			}
			rep(j, sy) {
				if(tab[bx - 1][j + by] == 2) {
					good
	}
	return res;
}
 
class RotatingTriangles {
	public:
	int count(vector <string> grid) {
		int res = 0;
		int n = (int) grid.size();
		int m = (int) grid[0].size();
		rep(i, n) {
			rep(j, m) {
				tab[i + 1][j + 1] = toTab(grid[i][j]);
			}
		}

		rep(i, n + 2) {
			rep(j, m + 2) {
				printf("%i", tab[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		repbe(i, 1, n) {
			repbe(j, 1, m) {
				if(tab[i][j] == 2) {
					printf("(%i, %i)\n", i, j);
					res += test(i, j, i, j);
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"#//#./#/#",
 "####.#/##",
 "...../#.#",
 ".....####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {".#.",
 "#/#",
 ".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {".../...",
 "..///./",
 ".//#/./"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	RotatingTriangles ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
