#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct
{
	int MAX;
	int MIN;
}Node;

vector <Node> segtree;
vector <vector<pair<int, int>>> node;
vector <int> sz;
vector <int> parent;
vector <int> depth;
vector <int> section;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int N, M, cnt;

Node upt(Node a, Node b)
{
	return { max(a.MAX, b.MAX), min(a.MIN, b.MIN) };
}

void update(int n, int start, int end, int index, int change)
{
	if (start == end)
		segtree[n] = { change, change };
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

Node get_MAX_MIN(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return { 0, 1000001 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_MAX_MIN(n * 2, start, (start + end) / 2, left, right), get_MAX_MIN(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
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

	if (n != 1)
		update(1, 0, N - 1, cnt, w);
	section[n] = cnt++;
	int heavy = -1;
	int weight;
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
		if (node[n][i].first != pn && node[n][i].first != heavy)
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
	int u, v, w;
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)), { 0, 1000001 });
	node = vector<vector<pair<int, int>>>(N + 1);
	sz = vector<int>(N + 1);
	section = vector <int>(N + 1);
	parent = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		node[v].push_back(make_pair(u, w));
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		int t = LCA(u, v);
		Node ans = { 0, 1000001 };
		while (chain_number[t] != chain_number[u])
		{
			ans = upt(ans, get_MAX_MIN(1, 0, N - 1, section[chain_number[u]], section[u]));
			u = parent[chain_number[u]];
		}
		ans = upt(ans, get_MAX_MIN(1, 0, N - 1, section[t] + 1, section[u]));
		while (chain_number[t] != chain_number[v])
		{
			ans = upt(ans, get_MAX_MIN(1, 0, N - 1, section[chain_number[v]], section[v]));
			v = parent[chain_number[v]];
		}
		ans = upt(ans, get_MAX_MIN(1, 0, N - 1, section[t] + 1, section[v]));
		cout << ans.MIN << ' ' << ans.MAX << '\n';
	}

	return 0;
}