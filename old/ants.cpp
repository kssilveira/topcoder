#include <stdio.h>
#include <queue>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <map>
#include <vector>

using namespace std;
vector<unsigned long long> pdist[100010];
			bool went[100050];
			unsigned long long dist[100010];
	vector<pair<int, int> > graph[100010];
		bool did[100010];

int main()
{
	int n, a, l, q, s, t;
	scanf("%i", &n);
	while(n) {
		for(int i = 0; i < n; i++)
			graph[i].clear();

		for(int i = 1; i <= n - 1; i++) {
			scanf("%i%i", &a, &l);
			graph[i].push_back(make_pair(a, l));
			graph[a].push_back(make_pair(i, l));
		}

		/*
		for(int i = 0; i < n; i++) {
			printf("%i: ", i);
			for(int j = 0; j < (int) graph[i].size(); j++) {
				printf("(%i,%i) ", graph[i][j].first, graph[i][j].second);
			}
			printf("\n");
		}
		printf("\n");//*/

		scanf("%i", &q);
		memset(did, 0, sizeof(did[0]) * n);

		unsigned long long res;
		for(int i = 0; i < q; i++) {
			scanf("%i%i", &s, &t);
			//printf("%i -> %i\n", s, t);

			if(!did[s] && !did[t]) {
				did[s] = true;
			

			dist[cur] = 0;
			memset(dist, 0xFF, sizeof(dist[0]) * n);
			memset(went, 0, sizeof(went[0]) * n);
			int cur = s;
			dist[cur] = 0;
			priority_queue<pair<unsigned long long, int> > q;
			q.push(make_pair(dist[cur], cur));
			while(!q.empty()) {
				cur = q.top().second;
				q.pop();

				if(went[cur]) continue;

				went[cur] = 1;

				//printf("(%i, %Lu)\n", cur, dist[cur]);

				for(int i = 0; i < (int) graph[cur].size(); i++) {
					unsigned long long nn = graph[cur][i].first,
							nl = graph[cur][i].second;
					if(dist[nn] > dist[cur] + nl) {
						dist[nn] = dist[cur] + nl;
						q.push(make_pair(dist[nn], nn));
					}
				}

				/*
				printf("dist: ");
				for(int i = 0; i < n; i++) {
					printf("%Li ", dist[i]);
				}
				printf("\n");//*/

				/*
				printf("went: ");
				for(int i = 0; i < n; i++) {
					printf("%i ", went[i]);
				}
				printf("\n");//*/

				//unsigned long long dmin = -1;
				//printf("went[0]: %i, dist[0]: %Lu, dmin: %Lu\n", went[0], dist[0], dmin);
				//int mini = -1;
				//for(int i = 0; i < n; i++) {
					//if(!went[i] && dist[i] < dmin) {
						//dmin = dist[i];
						//mini = i;
					//}
				//}
				//cur = mini;
			}
			pdist[s].reserve(n);
			for(int i = 0; i < n; i++) {
				pdist[s][i] = dist[i];
			}
			res = dist[t];
		} else if(did[s]) {
			res = pdist[s][t];
		} else {
			res = pdist[t][s];
		}
			
			if(i) cout << ' ';
			cout << res;
		}
		cout << endl;
		scanf("%i", &n);
	}
}
