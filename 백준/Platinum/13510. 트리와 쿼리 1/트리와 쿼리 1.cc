#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<pair<int, int>>> node;
vector <int> segtree;
vector <int> query;
vector <int> parent;
vector <pair<int, int>> edge;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, M;

void update(int n, int start, int end, int index, int w)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index, w);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index, w);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
	else
		segtree[n] = w;
}

int get_max(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return max(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void DFS(int n, int pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i].first != pn)
			DFS(node[n][i].first, n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int start_chain, int d, int w)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	int heavy = -1;
	int weight;
	if (n != 1)
		update(1, 0, N - 1, cnt, w);
	query[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
	{
		if (node[n][i].first != pn && (heavy == -1 || sz[node[n][i].first] > sz[heavy]))
		{
			heavy = node[n][i].first;
			weight = node[n][i].second;
		}
	}
	if (heavy != -1)
		HLD(heavy, n, start_chain, d, weight);

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i].first != heavy && node[n][i].first != pn)
			HLD(node[n][i].first, n, node[n][i].first, d + 1, node[n][i].second);
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
	int u, v, w, ch, n, c;
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 0);
	query = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	edge = vector<pair<int, int>>(N + 1);
	sz = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);
	node = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		node[v].push_back(make_pair(u, w));
		edge[i + 1] = make_pair(u, v);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch;
		if (ch == 1)
		{
			cin >> n >> c;
			pair<int, int> temp = edge[n];
			if (parent[temp.first] == temp.second)
				swap(temp.first, temp.second);
			update(1, 0, N - 1, query[temp.second] - 1, c);
		}
		else
		{
			cin >> u >> v;
			int t = LCA(u, v);
			int mx = 0;
			while (chain_number[t] != chain_number[u])
			{
				mx = max(mx, get_max(1, 0, N - 1, query[chain_number[u]] - 1, query[u] - 1));
				u = parent[chain_number[u]];
			}
			mx = max(mx, get_max(1, 0, N - 1, query[t], query[u] - 1));
			while (chain_number[t] != chain_number[v])
			{
				mx = max(mx, get_max(1, 0, N - 1, query[chain_number[v]] - 1, query[v] - 1));
				v = parent[chain_number[v]];
			}
			mx = max(mx, get_max(1, 0, N - 1, query[t], query[v] - 1));
			cout << mx << '\n';
		}
	}
}