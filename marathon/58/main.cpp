#include <cstdio>
#include <cstdlib>
#include <ctime>

inline int rand_between(int a, int b) {
  return rand() % (b - a + 1) + a;
}

// time 20 seconds
// size 100K
// memory 1024M

int main() {
  int x = 0, a, b;
  char str[100];
  //printf("%i\n", sizeof(unsigned long long));
  
  srand((unsigned) time(NULL));
  
  system("javac IsolatedPrimes.java");
  
  while(1) {
    x = rand_between(1, 500);
    a = rand_between(4 * x, 25 * x);
    b = rand_between(4 * x, 25 * x);
    x = 2; a = b = 5;
    x = 410; a = 5954; b = 1916;

    printf("(%3i, %5i, %5i)\n", x, a, b);
    system("javac IsolatedPrimes.java");
    sprintf(str, "java IsolatedPrimes %i %i %i", x, a, b);
    system(str);
    
    system("pause");
    //exit(0);
  }
  
  system("pause");
}
