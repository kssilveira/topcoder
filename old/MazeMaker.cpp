// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Mike Mazemeister has recently built a large maze in his backyard.  The j-th character of the i-th element of maze is 'X' if the square is an impassable bush; otherwise, it is a '.'.  Mike wants his friend, Jumping Jim, to solve the maze.  Jim will start in row startRow in column startCol.

Unlike typical maze solvers, Jim has the ability to jump through the maze, rather than simply walking.  Jim's possible moves are described in moveRow and moveCol.  The i-th element corresponds to a move Jim can make in which his current row is changed by moveRow[i], and his current column is changed by moveCol[i].  For example, if moveRow = {1, 0, -1} and moveCol = {3, -2, 5}, Jim's legal moves are (1,3), (0, -2), and (-1, 5).  However, Jim cannot move outside the boundary of the maze, and he cannot land on an impassable bush.

Mike wants to make the maze impossible for Jim to exit, and can place the exit in any cell containing a '.' in the maze.  If this turns out to be impossible, then Mike wants to make Jim's trip take as long as possible.  Jim is smart, and he will always exit the maze in the minimum number of jumps that he can.  Return the maximum number of jumps that Jim will make to exit the maze; if it is impossible for him to exit the maze, return -1 instead.


DEFINITION
Class:MazeMaker
Method:longestPath
Parameters:vector <string>, int, int, vector <int>, vector <int>
Returns:int
Method signature:int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-Each element of maze will contain the same number of characters.
-Each character of maze will be either 'X' or '.'.
-maze will contain at least 2 '.' characters.
-startRow will be between 0 and N-1, inclusive, where N is the number of elements in maze.
-startCol will be between 0 and M-1, inclusive, where M is the number of characters in each element of maze.
-maze[startRow][startCol] will be '.'.
-moveRow will contain between 1 and 50 elements, inclusive.
-moveCol will contain the same number of elements as moveRow.
-Each element of moveRow and moveCol will be between -50 and 50, inclusive.


EXAMPLES

0)
{"...",
 "...",
 "..."}
0
1
{1,0,-1,0}
{0,1,0,-1}

Returns: 3

Here Jim can move up, down, left and right.  Mike will set the exit in one of the bottom corners, which take Jim 3 steps to reach.

1)
{"...",
 "...",
 "..."}
0
1
{1, 0, -1, 0, 1, 1, -1, -1}
{0, 1, 0, -1, 1, -1, 1, -1}

Returns: 2

This is the same problem, but now Jim can move diagonally.  With this, he can reach any section in at most two steps.

2)
{"X.X",
 "...",
 "XXX",
 "X.X"}
0
1
{1, 0, -1, 0}
{0, 1, 0, -1}

Returns: -1

Here Mike can place the exit in the empty section of the bottom row; Jim can never reach it.

3)
{".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."}
5
0
{1, 0, -1, 0,-2, 1}
{0, -1, 0, 1, 3, 0}

Returns: 7



4)
{"......."}
0
0
{1, 0, 1, 0, 1, 0}
{0, 1, 0, 1, 0, 1}

Returns: 6



5)
{"..X.X.X.X.X.X."}
0
0
{2,0,-2,0}
{0,2,0,-2}

Returns: -1

Since Jim can only jump (and can't move to the side), Mike can place the exit anywhere except the start to prevent Jim from winning.

// END CUT HERE
#line 115 "MazeMaker.cpp"
#include <string>
#include <vector>
using namespace std;
class MazeMaker {
	public:
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1,0,-1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,1,0,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, -1, 0, 1, 1, -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, -1, 1, -1, 1, -1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(1, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"X.X",
 "...",
 "XXX",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, -1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, -1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(2, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 0; int Arr3[] = {1, 0, -1, 0,-2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, -1, 0, 1, 3, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 7; verify_case(3, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arr3[] = {1, 0, 1, 0, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, 1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(4, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"..X.X.X.X.X.X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arr3[] = {2,0,-2,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,2,0,-2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(5, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	MazeMaker __test;
	__test.run_test(-1);
}
// END CUT HERE
