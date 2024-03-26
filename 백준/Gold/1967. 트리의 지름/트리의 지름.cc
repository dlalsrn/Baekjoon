#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, u, v, c, mx = -1, n;
vector <vector<pi>> node;
vector <int> cost;

void dfs(int pn, int n)
{
	for (pi x : node[n])
	{
		if (x.first != pn)
		{
			cost[x.first] = cost[n] + x.second;
			dfs(n, x.first);
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node.resize(N + 1);
	cost.resize(N + 1, -1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> c;
		node[u].push_back(make_pair(v, c));
		node[v].push_back(make_pair(u, c));
	}

	cost[1] = 0;
	dfs(-1, 1);

	for (int i = 1; i <= N; i++)
	{
		if (cost[i] > mx)
		{
			mx = cost[i];
			n = i;
		}
	}

	cost.resize(N + 1, -1);
	cost[n] = 0;
	dfs(-1, n);

	mx = 0;
	for (int i = 1; i <= N; i++)
		mx = max(mx, cost[i]);

	cout << mx;
			
	return 0;
}