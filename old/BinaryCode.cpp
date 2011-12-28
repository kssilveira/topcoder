#include <iostream>
#include <vector>
#include <string>

#define MAX 52

using namespace std;

class BinaryCode {
public:
  int i, s, n, p[2][52], q[52];
  char temp[52];
  vector <string> decode(string message) {
    n = message.size();
    for(i = 0; i < n; i++) q[i] = message[i] - '0';
    
    //cout << n << " " << message << endl;
    
    vector<string> res;
    for(s = 0; s < 2; s++) {
      p[s][0] = s;
      p[s][1] = q[0] - p[s][0];
      for(i = 2; i < n; i++) {
        p[s][i] = q[i - 1] - p[s][i - 1] - p[s][i - 2];
        if(p[s][i] != 0 && p[s][i] != 1) break;
      }
      
      if((n == 1 && q[0] != s) || (n != 1 && (q[n - 1] != p[s][n - 2] + p[s][n - 1])) || (n != 1 && i != n) || (p[s][1] != 0 && p[s][1] != 1))
        res.push_back("NONE");
      else {
        for(i = 0; i < n; i++)
          temp[i] = p[s][i] + '0';
        temp[n] = 0;
        res.push_back(temp);
      }
      /*
      for(i = 0; i < n; i++)
      	cout << p[s][i];
      cout << endl;//*/
    }
    return res;
  }
};
