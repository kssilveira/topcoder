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

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
 
class ActivateGame {
	public:
	int findMaxScore(vector <string> grid) {
		int res = 0;
		int n = grid.size(), m = grid[0].size();
		int mat[60][60], went[60][60];
 
		rep(i, n)
			rep(j, m)
				if(grid[i][j] >= '0' && grid[i][j] <= '9')
					mat[i][j] = grid[i][j] - '0';
				else if(grid[i][j] >= 'a' && grid[i][j] <= 'z')
					mat[i][j] = grid[i][j] - 'a' + 10;
				else mat[i][j] = grid[i][j] - 'A' + 36;

		//rep(i, n) {
			//rep(j, m)
				//printf("%i ", mat[i][j]);
			//printf("\n");
		//}
		//printf("\n");
 
		memset(went, 0, sizeof(went));
		went[0][0] = 1;

		rep(num, n * m - 1) {
			int bi, bj, bv = -1, x, y;
			rep(i, n)
				rep(j, m) {
					if(!went[i][j]) continue;
					rep(d, 4) {
						x = i + dx[d];
						y = j + dy[d];
						if(x < 0 || x >= n || y < 0 || y >= m) continue;
						if(went[x][y]) continue;
						if(abs(mat[i][j] - mat[x][y]) > bv) {
							bv = abs(mat[i][j] - mat[x][y]);
							bi = x;
							bj = y;
						}
					}
				}
			went[bi][bj] = true;
			res += bv;
		}
 
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"05",
 "aB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 69; verify_case(0, Arg1, findMaxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"03",
 "21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, findMaxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {"John",
 "Brus",
 "Gogo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 118; verify_case(2, Arg1, findMaxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "AAA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, findMaxScore(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
int main()
{
	ActivateGame ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
