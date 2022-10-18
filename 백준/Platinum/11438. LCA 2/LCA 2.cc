#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int sz[100005], par[100005];

int dfs(int i, int p)
{
	par[i] = p;
	sz[i] = 1;
	for (int x : adj[i])
		if (x != p)
			sz[i] += dfs(x, i);
	return sz[i];
}

vector<int> chain[100005];
int depth[100005];
int chain_number[100005], chain_index[100005];

void HLD(int i, int p, int cur_chain, int d)
{
	depth[i] = d;
	chain_number[i] = cur_chain;
	chain_index[i] = chain[cur_chain].size();
	chain[cur_chain].push_back(i);

	int heavy = -1;
	for (int x : adj[i])
		if (x != p && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;
	if (heavy != -1)
		HLD(heavy, i, cur_chain, d);
	for (int x : adj[i])
		if (x != p && x != heavy)
			HLD(x, i, x, d + 1);
}

int LCA(int a, int b)
{
	while (chain_number[a] != chain_number[b])
	{
		if (depth[a] > depth[b])
			a = par[chain_number[a]];
		else
			b = par[chain_number[b]];
	}
	return chain_index[a] > chain_index[b] ? b : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i;
	cin >> n;
	for (i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	HLD(1, 0, 1, 0);
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}