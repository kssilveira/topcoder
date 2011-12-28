#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define SIZE 55


	int donuts[SIZE][SIZE][SIZE][SIZE];
class DonutsOnTheGridEasy {
		//x0, y0, width, height
	int m, n;
	public:
	int calc(vector <string> grid) {
#if 1
		//printf("here\n");
		
		m = grid.size();
		
		//printf("here\n");
		
		n = grid[0].size();
		
		//printf("here\n");
		
		for(int w = 1; w < 3; w++)
			for(int h = 1; h < 3; h++)
				for(int i = 0; i < m - w + 1; i++)
					for(int j = 0; j < n - h + 1; j++)
						donuts[i][j][w][h] = 0;
		
		//printf("here\n");
		
		for(int width = 3; width <= m; width++) {
			for(int height = 3; height <= n; height++) {
				for(int i = 0; i < m - width + 1; i++) {
					for(int j = 0; j < n - height + 1; j++) {
						bool wrong = false;
						for(int k = 0; k < width && !wrong; k++)
							if(grid[i + k][j] != '0' || grid[i + k][j + height - 1] != '0')
								wrong = true;
						for(int k = 0; k < height && !wrong; k++)
							if(grid[i][j + k] != '0' || grid[i + width - 1][j + k] != '0')
								wrong = true;
						if(!wrong) {
							//printf("found at (%i, %i) with (%i, %i)\n", i, j, width, height);
							int max = 0;
							for(int k = i + 1; k < i + width - 1; k++) {
								for(int l = j + 1; l < j + height - 1; l++) {
									for(int w = 3; w <= i + width - 1 - k; w++) {
										for(int h = 3; h <= j + height - 1 - l; h++) {
											if(donuts[k][l][w][h] > max)
												max = donuts[k][l][w][h];
										}
									}
								}
							}
							//donuts[i][j][width][height] = 1 + donuts[i + 1][j + 1][width - 2][height - 2];
							donuts[i][j][width][height] = 1 + max;
						} else {
							donuts[i][j][width][height] = donuts[i + 1][j + 1][width - 2][height - 2];
						}
					}
				}
			}
		}
		
		int res = 0;
		for(int width = 3; width <= m; width++) {
			for(int height = 3; height <= n; height++) {
				for(int i = 0; i < m - width + 1; i++) {
					for(int j = 0; j < n - height + 1; j++) {
						if(donuts[i][j][width][height] > res)
							res = donuts[i][j][width][height];
							}}}}
		return res;
#endif
	}

	
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
