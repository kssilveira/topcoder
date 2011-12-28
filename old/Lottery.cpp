//AR(c, b) c^b
//CR(c, b) 
//A(c, b)
//C(c, b)

//ainda não passa em todos os testes

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct t {
  char name[42];
  int c, b;
  bool s, u;
  long long w;
} rule;

int comp(const void *r, const void *d) {
	rule *sr = (rule *)r, *sd = (rule *)d;
	if(sr->w > sd->w) return 1;
	else if(sr->w == sd->w)
		return strcmp(sr->name, sd->name);
	return -1;
}

class Lottery {
public:
  rule r[52];
  long long comb[107][9];
  long long ar(int c, int b) {
  	long long res = 1;
  	for(int i = 0; i < b; i++) res *= c;
  	return res;
  }
  
  long long cr(int c, int b) {
  	return comb[c + b - 1][b];
  }
  
  long long a(int c, int b) {
  	long long res = 1;
  	for(int i = 0; i < b; i++) res *= c--;
  	return res;
  }
  
  void fillComb() {
  	int i, n, k;
  	for(i = 0; i <= 8; i++)
  		comb[i][i] = 1;
  	for(n = 1; n <= 107; n++) {
  		comb[n][0] = 1;
  		for(k = 1; k < n && k <= 8; k++)
  			comb[n][k] = comb[n - 1][k - 1] + comb[n - 1][k];
  	}
  	
  	/*
  	for(n = 0; n <= 107; n++) {
  		for(k = 0; k <= n && k <= 8; k++)
  			cout << comb[n][k] << " ";
  		cout << endl;
  	}//*/
  }
  
  vector <string> sortByOdds(vector <string> rules) {
  	char c, d;
  	int n = rules.size(), i;
  	//cout << n;
  	
  	if(n)
  		fillComb();
  	
  	for(i = 0; i < n; i++) {
  		sscanf(rules[i].c_str(), "%[^:]: %i %i %c %c", r[i].name, &r[i].c, &r[i].b, &c, &d);
  		r[i].s = c == 'T' ? true : false;
  		r[i].u = d == 'T' ? true : false;
  		
  		if(!r[i].s && !r[i].u) {
  			r[i].w = ar(r[i].c, r[i].b);
  		} else if(r[i].s && !r[i].u) {
  			r[i].w = cr(r[i].c, r[i].b);
		} else if(!r[i].s && r[i].u) {
			r[i].w = a(r[i].c, r[i].b);
		} else if(r[i].s && r[i].u) {
			r[i].w = comb[r[i].c][r[i].b];
		}
		
  		//printf("%s: %i %i %c %c %lli\n", r[i].name, r[i].c, r[i].b, r[i].s ? 'T' : 'F', r[i].u ? 'T' : 'F', r[i].w);
  	}
  	
  	if(n)
  		qsort(r, n, sizeof(r[i]), comp);
  	
	vector <string> res;
	for(i = 0; i < n; i++)
		res.push_back(r[i].name);
	return res;
  }
};
