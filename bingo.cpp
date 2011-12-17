#include <cstdio>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, b, ball[100];
	scanf("%i%i", &n, &b);
	while(n || b) {
		for(int i = 0; i < b; i++) {
			scanf("%i", &ball[i]);
			//printf("ball[%i]: %i\n", i, ball[i]);
		}
		int found[100] = {0};
		memset(found, 0, sizeof(found));
		for(int i = 0; i < b; i++) {
			for(int j = 0; j < b; j++) {
				if(ball[i] < ball[j]) {
					found[ball[j] - ball[i]] = 1;
				} else {
					found[ball[i] - ball[j]] = 1;
				}
			}
		}
		bool ff = false;
		for(int i = 0; i <= n; i++) {
			//printf("found[%i] = %i\n", i, found[i]);
			if(!found[i]) {
				ff = true;
				break;
			}
		}
		printf("%s\n", !ff ? "Y" : "N");

		scanf("%i%i", &n, &b);
	}
}
