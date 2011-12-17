#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sType
{
	int s, f;
} Type;

int myless(const void *vl, const void *vr)
{
	Type *l = (Type *)vl,
			 *r = (Type *)vr;
	return l->f - r->f;
}

int main()
{
	int m, n;
	Type v[110];
	scanf("%i%i", &m, &n);
	while(m || n) {
		for(int i = 0;i < n; i++) {
			scanf("%i%i", &v[i].s, &v[i].f);
		}
		qsort(v, n, sizeof(v[0]), myless);

		/*
		for(int i = 0; i < n; i++) {
			printf("(%i, %i) ", v[i].s, v[i].f);
		}
		printf("\n");//*/

		unsigned long long res = 0;
		unsigned long long pd[110] = {0};
		bool dep[110][110];
		memset(dep, 0, sizeof(dep));
		for(int i = 0; i < n; i++) {
			pd[i] = 0;
			if(v[i].s == 0) {
				pd[i] = 1;
			}
			for(int j = i - 1; j >= 0; j--) {
				if(!dep[i][j] && v[j].f >= v[i].s && v[j].s < v[i].s
						&& v[j].f < v[i].f) {
					pd[i] += pd[j];
					dep[i][j] = true;
					for(int k = 0; k < n; k++) {
						dep[i][k] = dep[i][k] || dep[j][k];
					}
				}
			}
			if(v[i].f == m) {
				res += pd[i];
			}
			//printf("%Lu ", pd[i]);
		}
		
		//printf("\n");
		//printf("\n");

		/*
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				printf("%i ", dep[i][j]);
			}
			printf("\n");
		}
		printf("\n");//*/

		printf("%Lu\n", res);

		scanf("%i%i", &m, &n);
	}
}

