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

typedef struct Country
{
	string name;
	int gold, silver, bronze;
}sCountry;

class Comp{
	public:
		bool operator()(const sCountry &l, const sCountry &r) {
			if(l.gold < r.gold) return true;
			if(l.gold > r.gold) return false;
			if(l.silver < r.silver) return true;
			if(l.silver > r.silver) return false;
			if(l.bronze < r.bronze) return true;
			if(l.bronze > r.bronze) return false;
			if(l.name > r.name) return true;
			if(l.name < r.name) return false;
			return false;
		}
}comp;

class MedalTable {
	public:
	vector <string> generate(vector <string> results) {
		vector <string> res;
		vector<sCountry> country;
		int n = results.size();

		
		set<string> names;
		map<string, int> golds, silvers, bronzes;
		rep(i, n) {
			golds  [string("") + results[i][0] + results[i][1] + results[i][2]]++;
			silvers[string("") + results[i][4] + results[i][5] + results[i][6]]++;
			bronzes[string("") + results[i][8] + results[i][9] + results[i][10]]++;
			names.insert(string("") + results[i][0] + results[i][1] + results[i][2]);
			names.insert(string("") + results[i][4] + results[i][5] + results[i][6]);
			names.insert(string("") + results[i][8] + results[i][9] + results[i][10]);
		}
			
		int count = 0;
		map<string, int>::iterator j;
		for(set<string>::iterator i = names.begin(); i != names.end(); ++i) {
			sCountry temp;
			country.push_back(temp);

			country[count].name = *i;
			country[count].gold = country[count].silver = country[count].bronze = 0;
			if((j = golds.find(*i)) != golds.end()) {
				country[count].gold = j->second;
			}
			if((j = silvers.find(*i)) != silvers.end()) {
				country[count].silver= j->second;
			}
			if((j = bronzes.find(*i)) != bronzes.end()) {
				country[count].bronze = j->second;
			}
			count++;
		}

		sort(country.begin(), country.end(), comp);
		reverse(country.begin(), country.end());

		rep(i, count) {
			char str[100];
			sprintf(str, "%s %i %i %i", country[i].name.c_str(),
					country[i].gold, country[i].silver, country[i].bronze);
			res.push_back(str);
		}

		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main()
{
	MedalTable ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 
