#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> node;
vector <int> segtree;
vector <int> lazy;
vector <int> section;
vector <int> parent;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int N, M, u, v, a, b, cnt;

void Lazy(int n, int start, int end)
{
	if (lazy[n] != -1)
	{
		segtree[n] = lazy[n];
		if (start != end)
		{
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = -1;
	}
}

void update(int n, int start, int end, int left, int right, int w)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		lazy[n] = w;
		Lazy(n, start, end);
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, w);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, w);
		segtree[n] = min(segtree[n * 2], segtree[n * 2 + 1]);
	}
		
}

int get_min(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
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
	for (int x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int start_chain, int d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	int heavy = -1;
	section[n] = cnt++;
	for (int x : node[n])
		if (x != pn && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;

	if (heavy != -1)
		HLD(heavy, n, start_chain, d);

	for (int x : node[n])
		if (x != heavy && x != pn)
			HLD(x, n, x, d + 1);
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
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 1);
	lazy = vector<int>((1 << (h + 1)), -1);
	section = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);
	node = vector<vector<int>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[v].push_back(u);
		node[u].push_back(v);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> a >> b;
		int t = LCA(u, v);
		int c = LCA(a, b);
		int mn = 1;

		// update
		while (chain_number[t] != chain_number[u])
		{
			update(1, 0, N - 1, section[chain_number[u]] + 1, section[u], 0);
			u = parent[chain_number[u]];
		}
		update(1, 0, N - 1, section[t] + 1, section[u], 0);
		while (chain_number[t] != chain_number[v])
		{
			update(1, 0, N - 1, section[chain_number[v]] + 1, section[v], 0);
			v = parent[chain_number[v]];
		}
		update(1, 0, N - 1, section[t] + 1, section[v], 0);

		// 최솟값 찾기
		while (chain_number[c] != chain_number[a])
		{
			mn = min(mn, get_min(1, 0, N - 1, section[chain_number[a]] + 1, section[a]));
			a = parent[chain_number[a]];
		}
		mn = min(mn, get_min(1, 0, N - 1, section[c] + 1, section[a]));
		while (chain_number[c] != chain_number[b])
		{
			mn = min(mn, get_min(1, 0, N - 1, section[chain_number[b]] + 1, section[b]));
			b = parent[chain_number[b]];
		}
		mn = min(mn, get_min(1, 0, N - 1, section[c] + 1, section[b]));

		cout << (mn ? "YES" : "NO") << '\n';

		// update
		while (chain_number[t] != chain_number[u])
		{
			update(1, 0, N - 1, section[chain_number[u]] + 1, section[u], 1);
			u = parent[chain_number[u]];
		}
		update(1, 0, N - 1, section[t] + 1, section[u], 1);
		while (chain_number[t] != chain_number[v])
		{
			update(1, 0, N - 1, section[chain_number[v]] + 1, section[v], 1);
			v = parent[chain_number[v]];
		}
		update(1, 0, N - 1, section[t] + 1, section[v], 1);
	}

	return 0;
}