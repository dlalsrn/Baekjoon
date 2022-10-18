#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <vector<int>> node;
vector <int> E;
vector <int> segtree;
vector <int> query;
vector <int> parent;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, Q;

void update(int n, int start, int end, int index, int change)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = segtree[n * 2] ^ segtree[n * 2 + 1];
	}
	else
		segtree[n] = change;
}

int get_XOR(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_XOR(n * 2, start, (start + end) / 2, left, right) ^ get_XOR(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
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

	update(1, 0, N - 1, cnt, E[n]);
	query[n] = cnt++;
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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n1, n2, ch, l, r;
	cin >> N >> Q;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)));
	node = vector<vector<int>>(N + 1);
	chain = vector<vector<int>>(N + 1);
	E = vector<int>(N + 1);
	query = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> E[i];
	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	for (int q = 0; q < Q; q++)
	{
		cin >> ch >> l >> r;
		int ans = 0;
		if (ch == 1)
			update(1, 0, N - 1, query[l], r);
		else
		{
			int t = LCA(l, r);
			while (chain_number[t] != chain_number[l])
			{
				ans ^= get_XOR(1, 0, N - 1, query[chain_number[l]], query[l]);
				l = parent[chain_number[l]];
			}
			ans ^= get_XOR(1, 0, N - 1, query[t], query[l]);
			while (chain_number[t] != chain_number[r])
			{
				ans ^= get_XOR(1, 0, N - 1, query[chain_number[r]], query[r]);
				r = parent[chain_number[r]];
			}
			ans ^= get_XOR(1, 0, N - 1, query[t], query[r]);
			ans ^= get_XOR(1, 0, N - 1, query[t], query[t]);
			cout << ans << '\n';
		}
	}
}