#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

#define ABSNUM(x) ((x) > 0 ? (x) : (-(x)))

class MinimalDifference {
	public:
	int findNumber(int A, int B, int C) {
		int min = INT_MAX, res = 0, csum = digitSum(C);
		for(int i = A; i <= B; i++) {
			int sum = digitSum(i), dif = ABSNUM(sum - csum);
			if(dif < min) {
				min = dif;
				res = i;
			}
		}
		return res;
	}

	int digitSum(int x) {
		int res = 0;
		while(x) {
			res += x % 10;
			x /= 10;
		}
		return res;
	}
};
