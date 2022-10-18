#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> node;
vector <int> segtree;
vector <int> query;
vector <int> parent;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, M;

void update(int n, int start, int end, int index)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index);
		segtree[n] = min(segtree[n * 2], segtree[n * 2 + 1]);
	}
	else
		segtree[n] = 0;
}

int get_min(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 1;
	if (left <= start && end <= right)
		return segtree[n];
	return min(get_min(n * 2, start, (start + end) / 2, left, right), get_min(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void DFS(int n, int pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn)
			DFS(node[n][i], n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int start_chain, int d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	int heavy = -1;
	query[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn && (heavy == -1 || sz[node[n][i]] > sz[heavy]))
			heavy = node[n][i];
	if (heavy != -1)
		HLD(heavy, n, start_chain, d);

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != heavy && node[n][i] != pn)
			HLD(node[n][i], n, node[n][i], d + 1);
}

int LCA(int u, int v)
{
	while (chain_number[u] != chain_number[v])
	{
		if (depth[u] > depth[v])
			u = parent[chain_number[u]];
		else
			v = parent[chain_number[v]];
	}
	return chain_index[u] > chain_index[v] ? v : u;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int p, b, c, d;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 1);
	query = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);
	node = vector<vector<int>>(N + 1);

	for (int i = 2; i <= N; i++)
	{
		cin >> p;
		node[p].push_back(i);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> b >> c >> d;
		int ori_b = b, ori_c = c;
		int mn = 1;
		int t = LCA(b, c);

		while (chain_number[t] != chain_number[b])
		{
			mn = min(mn, get_min(1, 0, N - 1, query[chain_number[b]] - 1, query[b] - 1));
			b = parent[chain_number[b]];
		}
		mn = min(mn, get_min(1, 0, N - 1, query[t], query[b] - 1));
		while (chain_number[t] != chain_number[c])
		{
			mn = min(mn, get_min(1, 0, N - 1, query[chain_number[c]] - 1, query[c] - 1));
			c = parent[chain_number[c]];
		}
		mn = min(mn, get_min(1, 0, N - 1, query[t], query[c] - 1));

		if (mn == 0)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		if (d == 1)
		{
			if (mn == 1)
				update(1, 0, N - 1, query[ori_b] - 1);
			else
				update(1, 0, N - 1, query[ori_c] - 1);
		}
	}
}