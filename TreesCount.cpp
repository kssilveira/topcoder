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

#define MAX_SIZE 51
#define MOD 1000000007

bool went[MAX_SIZE];
int dist[MAX_SIZE];
int alt[MAX_SIZE];

class Comp
{
	public:
		bool operator() (const pair<int, int> &l, const pair<int, int> &r)
		{
			if(l.first > r.first) return true;
			if(l.first < r.first) return false;
			if(l.second > r.second) return true;
			if(l.second < r.second) return false;
			return false;
		}
};

int n;
map<unsigned long long, unsigned long long> m;

class TreesCount {
	public:
	vector<string> graph;
	int count(vector <string> graph) {
		m.clear();

		n = graph.size();
		this->graph = graph;

		priority_queue<pair<int, int>, vector<pair<int, int> >, Comp > q;
		q.push(make_pair(0, 0));
		memset(went, 0, sizeof(went));
		memset(dist, 0, sizeof(dist));
		while(!q.empty()) {
			pair<int, int> p = q.top();
			int cx = p.second, cc = p.first;
			q.pop();
			//printf("on %i %i\n", cc, cx);
			if(went[cx]) continue;
			went[cx] = true;
			dist[cx] = cc;
			rep(i, n) {
				if(!went[i] && graph[cx][i] != '0') {
					//printf("inseting %i %i\n", graph[cx][i] - '0' + cc, i);
					q.push(make_pair(graph[cx][i] - '0' + cc, i));
				}
			}
		}

		rep(i, n) {
			printf("dist[%i] = %i\n", i, dist[i]);
		}

		memset(went, 0, sizeof(went));
		//memset(alt, 0, sizeof(alt));


		dfs(0, 0, 0);

		unsigned long long tres = 0;
		for(map<unsigned long long, unsigned long long>::iterator i = m.begin(); i != m.end(); ++i) {
			unsigned long long om = (~i->first) & ((((unsigned long long)1) << (n - 1)) - 1);
			cout << "first: " << i->first << " map: " << i->second << " om: " << om << endl;
			map<unsigned long long, unsigned long long>::iterator j;
			if((j = m.find(om)) != m.end()) {
				tres += (i->second * j->second) % MOD;
				tres %= MOD;
			}
		}


		
		//rep(i, n) {
			//printf("alt[%i] = %i\n", i, alt[i]);
		//}

		//unsigned long long tres = 1;
		//rep(i, n) {
			//tres = (tres * alt[i]) % MOD;
			//tres %= MOD;
		//}

		return tres / 2;
	}
	void dfs(int cur, int cd, unsigned long long mask)
	{
		went[cur] = true;
		if(cd == dist[cur]) {
			//alt[cur]++;
			cout << "mask: " << mask << " cur: " << cur << endl;
			cout << "m[mask]: " << m[mask] << endl;
			m[mask]++;
			m[mask] %= MOD;
		} else {
			return;
		}
		rep(i, n) {
			if(!went[i] && graph[cur][i] != '0') {
				went[i] = true;
				dfs(i, cd + graph[cur][i] - '0', mask | (1 << (i - 1)));
				went[i] = false;
			}
		}
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"021",
 "201",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123",
 "1012",
 "2101",
 "3210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	TreesCount ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
