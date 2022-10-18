#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector <ll> segtree;
vector <vector<int>> node;
vector <ll> lazy;
vector <int> parent;
vector <int> section;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, M;

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

	section[n] = cnt++;
	int heavy = -1;
	for (int x : node[n])
		if (x != pn && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;
	if (heavy != -1)
		HLD(heavy, n, start_chain, d);

	for (int x : node[n])
		if (x != pn && x != heavy)
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

void Lazy(int n, int start, int end)
{
	if (lazy[n] != 0)
	{
		segtree[n] += lazy[n] * (end - start + 1);
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		segtree[n] += end - start + 1;
		if (start != end)
		{
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

ll get_sum(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int u, v;
	char ch;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<ll>((1 << (h + 1)), 0);
	lazy = vector<ll>((1 << (h + 1)));
	node = vector<vector<int>>(N + 1);
	sz = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	section = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> u >> v;
		int t = LCA(u, v);
		if (ch == 'P')
		{
			while (chain_number[t] != chain_number[u])
			{
				update(1, 0, N - 1, section[chain_number[u]], section[u]);
				u = parent[chain_number[u]];
			}
			update(1, 0, N - 1, section[t] + 1, section[u]);
			while (chain_number[t] != chain_number[v])
			{
				update(1, 0, N - 1, section[chain_number[v]], section[v]);
				v = parent[chain_number[v]];
			}
			update(1, 0, N - 1, section[t] + 1, section[v]);
		}
		else
		{
			ll sum = 0;
			while (chain_number[t] != chain_number[u])
			{
				sum += get_sum(1, 0, N - 1, section[chain_number[u]], section[u]);
				u = parent[chain_number[u]];
			}
			sum += get_sum(1, 0, N - 1, section[t] + 1, section[u]);
			while (chain_number[t] != chain_number[v])
			{
				sum += get_sum(1, 0, N - 1, section[chain_number[v]], section[v]);
				v = parent[chain_number[v]];
			}
			sum += get_sum(1, 0, N - 1, section[t] + 1, section[v]);
			cout << sum << '\n';
		}
	}
	return 0;
}