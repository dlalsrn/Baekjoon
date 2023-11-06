#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, M, u, v, w, s, e;
vector <vector<pi>> node;
vector <int> weight;
priority_queue <pi> pq;

void bfs()
{
	while (!pq.empty())
	{
		int now = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		if (now == e)
		{
			cout << w;
			break;
		}

		if (now != s && w < weight[now])
			continue;

		for (pi x : node[now])
		{
			int n = x.first;
			int cost = x.second;
			int mx = min(cost, weight[now]);

			if (mx > weight[n])
			{
				weight[n] = mx;
				pq.push(make_pair(mx, n));
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N >> M;

	node = vector<vector<pi>>(N + 1);
	weight = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u].emplace_back(v, w);
		node[v].emplace_back(u, w);
	}

	cin >> s >> e;

	weight[s] = 1e9 + 1;
	pq.push(make_pair(1e9+1, s));
	bfs();

	return 0;
}