#include <stdio.h>
#include <string.h>
#include <climits>
#include <algorithm>
#include <vector>

int res = INT_MAX;

using namespace std;

int went[5000];
int dist[5000];
vector<int> graph[5000];

void dfs(int cur, int dst, int last)
{
	//printf("dfs: %i %i\n", cur + 1, dst);
	if(went[cur] == 1) {
		res = max(res, dst - dist[cur]);
		//printf("res: %i\n", res);
		return;
	} else if(went[cur] == 2) {
		return;
	}
	went[cur] = 1;
	int old = dist[cur];
	dist[cur] = dst;
	int n = (int) graph[cur].size();
	for(int i = 0; i < n; i++) {
		if(graph[cur][i] != last) {
			dfs(graph[cur][i], dst + 1, cur);
		}
	}
	dist[cur] = old;
	went[cur] = 2;
}

int main()
{
	int T, n, m, a, b;
	//freopen("d.in", "r", stdin);
	scanf("%i", &T);
	for(int t = 0; t < T; t++) {
		scanf("%i%i", &n, &m);

		for(int i = 0; i < n; i++) {
			graph[i].clear();
		}

		for(int i = 0; i < m; i++) {
			scanf("%i%i", &a, &b);
			a--;
			b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		/*
		for(int i = 0; i < n; i++) {
			int n = graph[i].size();
			printf("%i: ", i + 1);
			for(int j = 0; j < n; j++) {
				printf("%i ", graph[i][j] + 1);
			}
			printf("\n");
		}
		printf("\n");//*/

		memset(went, 0, sizeof(went));
		memset(dist, 0, sizeof(dist));
		res = 0;
		dfs(0, 0, -1);

		printf("%i\n", res);
	}
	return 0;
}

