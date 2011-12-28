#include <stdio.h>
#include <algorithm>

using namespace std;
int main()
{
	int a, b;
	scanf("%i%i", &a, &b);
	while(a || b) {
		int temp = a;
		a = b;
		int count[10] = {0};

		int bb = 100, ac[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		while(a > bb) {
			for(int i = 0; i < 9; i++) {
				ac[i] *= 10;
				if(i)
					ac[i] += 10;
			}
			bb *= 10;
		}
		bb /= 10;
		for(int i = 0; i < 9; i++) {
			ac[i] *= a / bb;
			if(i) ac[i] += a / bb;
		}
		
		for(int i = bb + 1; i < a; i++) {
			int n = i;
			while(n) {
				ac[n % 10]++;
				n /= 10;
			}
		}

		printf("ac: ");
		for(int i = 0; i < 9; i++) {
			printf("%i ", ac[i]);
		}
		printf("\n");
		

		a = temp;
		for(int i = a; i <= b; i++) {
			int n = i;
			while(n) {
				count[n % 10]++;
				n /= 10;
			}
		}

		printf("%i", count[0]);
		for(int i = 1; i < 10; i++) {
			printf(" %i", count[i]);
		}
		printf("\n");

		scanf("%i%i", &a, &b);
	}
}

