#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WordsGame {
	public:
	int minimumSwaps(vector <string> grid, string word) {
		int n = word.size(), res = -1, tmp;
		for(int line = 0; line < n; line++) {
			tmp = solve(grid[line].c_str(), word.c_str());
			if(tmp != -1 && (tmp < res || res == -1))
				res = tmp;
		}
		for(int col = 0; col < n; col++) {
			string arg;
			for(int line = 0; line < n; line++) {
				char s[2] = {0};
				s[0] = grid[line][col];
				arg.append(s);
			}
			tmp = solve(arg.c_str(), word.c_str());
			if(tmp != -1 && (tmp < res || res == -1))
				res = tmp;
		}
		return res;
	}

	int solve(const char *rs, const char *t) {
		char s[52];
		strcpy(s, rs);
		int res = 0, cur;
		for(cur = 0; t[cur]; cur++) {
			int i;
			for(i = cur; s[i]; i++)
				if(s[i] == t[cur])
					break;
			if(!s[i])
				break;
			if(i != cur) {
				char tmp = s[i];
				s[i] = s[cur];
				s[cur] = tmp;
				res++;
			}
		}
		if(t[cur])
			return -1;
		return res;
	}
};
