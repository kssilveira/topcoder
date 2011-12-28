#include <stdio.h>

int main()
{
	int a[3], b[3];
	scanf("%i%i%i%i%i", &a[0], &a[1], &a[2], &b[0], &b[1]);
	while(a[0]) {
		bool used[60] = {0};
		used[a[0]] = used[a[1]] = used[a[2]] = 
			used[b[0]] = used[b[1]] = 1;
		int perm[][3] = {{1, 2, 3},
			{1, 3, 2},
			{2, 1, 3},
			{2, 3, 1},
			{3, 1, 2},
			{3, 2, 1}};
		bool solved = false;
		for(b[2] = 1; b[2] <= 52; b[2]++) {
			if(used[b[2]]) continue;
			bool foundlose = false;
			for(int i = 0; i < 6 && !foundlose; i++) {
				for(int j = 0; j < 6 && !foundlose; j++) {
					int win = 0;
					for(int k = 0; k < 3; k++) {
						if(b[perm[i][k] - 1] > a[perm[j][k] - 1])
							win++;
					}
					if(win < 2) {
						foundlose = true;
					}
				}
			}
			if(!foundlose) {
				solved = true;
				printf("%i\n", b[2]);
				break;
			}
		}
		if(!solved) {
			printf("-1\n");
		}

		scanf("%i%i%i%i%i", &a[0], &a[1], &a[2], &b[0], &b[1]);
	}
}
		
