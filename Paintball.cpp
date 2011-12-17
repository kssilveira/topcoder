#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map> //NEW
#include <algorithm> //NEW

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) reptbc(int, i, b, n, c)
#define reps(i, n) repbs(i, 0, n)
#define repbs(i, b, n) reptbc(unsigned int, i, b, n.size(), <)
#define reptbc(t, i, b, n, c) for(t i = b; i c n; i++)
#define repi(i, t, n) for(t::iterator i = n.begin(); i != n.end(); ++i) //NEW

using namespace std;

bool comp_score_team(pair<string, int> a, pair<string, int> b) {
  if(a.second < b.second) return true;
  if(a.second > b.second) return false;
  return a.first < b.first;
}

    typedef map<string, int> map_type;
    typedef map<string, string> map_type_b;
    map<string, int> score;
    map<string, string> team;
    map<string, int> score_team;
    vector<string> name_vector;
    vector<string> team_vector;
    
    
bool comp_team(string a, string b) {
  if(score_team[a] > score_team[b]) return true;
  if(score_team[a] < score_team[b]) return false;
  return a < b;
}

bool comp_name(string a, string b) {
  if(score[a] > score[b]) return true;
  if(score[a] < score[b]) return false;
  return a < b;
}

class Paintball {
	public:
    
	vector <string> getLeaderboard(vector <string> players, vector <string> messages) {
		vector <string> res;
		
		score.clear();
		team.clear();
		score_team.clear();
		name_vector.clear();
		team_vector.clear();

    char name[100], steam[100], namea[100], nameb[100], sres[100];
    
    reps(i, players) {
      sscanf(players[i].c_str(), "%s %s", name, steam);
      score[name] = 0;
      team[name] = steam;
      score_team[steam] = 0;
      name_vector.push_back(name);
    }

    repi(i, map_type, score_team) {
      team_vector.push_back(i->first);
    }
		
		reps(i, messages) {
      sscanf(messages[i].c_str(), "%s SPLATTERED %s", namea, nameb);
      if(team[namea] == team[nameb]) {
        score[namea]--;
      } else {
        score[namea]++;
        score[nameb]--;
      }
    }

    repi(i, map_type, score) {
      score_team[team[i->first]] += i->second;
    }

    sort(team_vector.begin(), team_vector.end(), (bool (*)(string, string)) comp_team);
    sort(name_vector.begin(), name_vector.end(), comp_name);

    reps(i, team_vector) {
      sprintf(sres, "%s %i", team_vector[i].c_str(), score_team[team_vector[i]]);
      res.push_back(sres);
      reps(j, name_vector) {
        if(team[name_vector[j]] == team_vector[i]) {
          sprintf(sres, "  %s %i", name_vector[j].c_str(), score[name_vector[j]]);
          res.push_back(sres);
        }
      }
    }

		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A RED", "B BLUE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"RED 1", "  A 1", "BLUE -1", "  B -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TODD STRIKEFORCE",
 "BART OMEGA",
 "DATA STRIKEFORCE",
 "MILHOUSE OMEGA",
 "NELSON DISCOVERYCHANNEL",
 "MARTIN DISCOVERYCHANNEL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"DR COHO", "ST COHO", "PE COHO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DR SPLATTERED ST",
 "ST SPLATTERED PE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"COHO -2", "  PE 0", "  DR -1", "  ST -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A B", "AA AA", "AAA AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA", 
"AA SPLATTERED AAA", "AA SPLATTERED AAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLeaderboard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Paintball __test;
	__test.run_test(-1);
	system("pause");
}
// END CUT HERE
