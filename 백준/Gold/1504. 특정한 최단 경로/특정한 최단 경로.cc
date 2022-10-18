#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector <vector<int>> all_dist;
vector <vector<pi>> node;
priority_queue <pi, vector<pi>, greater<pi>> q;
int N, M, V1, V2, u, v, w, mx;

void dijk(int s)
{
	while (!q.empty())
	{
		int next = q.top().second;
		int dist = q.top().first;
		q.pop();
		if (all_dist[s][next] < dist)
			continue;
		for (pi x : node[next])
		{
			if (all_dist[s][x.first] == -1 || all_dist[s][x.first] > dist + x.second)
			{
				all_dist[s][x.first] = dist + x.second;
				q.push(make_pair(all_dist[s][x.first], x.first));
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	node = vector<vector<pi>>(N + 1);
	all_dist = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		node[v].push_back(make_pair(u, w));
	}

	cin >> V1 >> V2;

	all_dist[1][1] = 0;
	q.push(make_pair(0, 1));
	dijk(1);
	all_dist[V1][V1] = 0;
	q.push(make_pair(0, V1));
	dijk(V1);
	all_dist[V2][V2] = 0;
	q.push(make_pair(0, V2));
	dijk(V2);

	if (all_dist[1][V1] == -1 || all_dist[V1][V2] == -1 || all_dist[V2][N] == -1)
		cout << -1;
	else
	{
		int a = all_dist[1][V1] + all_dist[V1][V2] + all_dist[V2][N];
		int b = all_dist[1][V2] + all_dist[V2][V1] + all_dist[V1][N];
		cout << (a < b ? a : b);
	}

	return 0;
}