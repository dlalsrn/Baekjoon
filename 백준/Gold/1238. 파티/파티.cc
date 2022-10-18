#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector <vector<int>> all_dist;
vector <vector<pi>> node;
priority_queue <pi, vector<pi>, greater<pi>> q;
int N, M, X, u, v, w, mx;

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
	cin >> N >> M >> X;
	node = vector<vector<pi>>(N + 1);
	all_dist = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= N; i++)
	{
		all_dist[i][i] = 0;
		q.push(make_pair(0, i));
		dijk(i);
	}

	for (int i = 1; i <= N; i++)
	{
		int i_dis = all_dist[i][X] + all_dist[X][i];
		mx = max(mx, i_dis);
	}

	cout << mx;
	return 0;
}