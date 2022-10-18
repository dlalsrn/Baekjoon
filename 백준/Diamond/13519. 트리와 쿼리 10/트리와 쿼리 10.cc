#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define NOT 10001
using namespace std;
typedef struct
{
	int L_MAX;
	int R_MAX;
	int T_MAX;
	int ALL;
}NODE;

vector <vector<int>> node;
vector <NODE> segtree;
vector <int> lazy;
vector <pair<int, int>> value;
vector <int> section;
vector <int> depth;
vector <int> sz;
vector <int> parent;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, M, u, v, w, ch;

void DFS(int n, int pn)
{
	parent[n] = pn;
	sz[n] = cnt++;
	for (int x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n];
}

void HLD(int n, int pn, int start_chain, int d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);
	section[n] = cnt++;
	value[cnt].second = value[n].first;

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

int LCA(int a, int b)
{
	while (chain_number[a] != chain_number[b])
	{
		if (depth[a] > depth[b])
			a = parent[chain_number[a]];
		else
			b = parent[chain_number[b]];
	}

	return chain_index[a] > chain_index[b] ? b : a;
}

NODE upt(NODE LEFT, NODE RIGHT)
{
	NODE t;
	t.L_MAX = max(LEFT.L_MAX, LEFT.ALL + RIGHT.L_MAX);
	t.R_MAX = max(RIGHT.R_MAX, RIGHT.ALL + LEFT.R_MAX);
	t.T_MAX = max(LEFT.T_MAX, max(RIGHT.T_MAX, LEFT.R_MAX + RIGHT.L_MAX));
	t.ALL = LEFT.ALL + RIGHT.ALL;
	return t;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = { value[start + 1].second, value[start + 1].second, value[start + 1].second, value[start + 1].second };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] != NOT)
	{
		int mx = max((end - start + 1) * lazy[n], lazy[n]);
		segtree[n] = { mx, mx, mx, (end - start + 1) * lazy[n] };
		if (start != end)
		{
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = NOT;
	}
}

void update(int n, int start, int end, int left, int right, int w)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		int mx = max((end - start + 1) * w, w);
		segtree[n] = { mx, mx, mx, (end - start + 1) * w };
		if (start != end)
		{
			lazy[n * 2] = w;
			lazy[n * 2 + 1] = w;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, w);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, w);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

NODE get_max(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return { -NOT, -NOT, -NOT, 0 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<NODE>((1 << (h + 1)));
	lazy = vector<int>((1 << h + 1), NOT);
	node = vector<vector<int>>(N + 1);
	value = vector<pair<int, int>>(N + 1);
	section = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> value[i].first;

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
	set_segtree(1, 0, N - 1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> u >> v;
		if (ch == 1)
		{
			int t = LCA(u, v);
			NODE L = { -NOT, -NOT, -NOT, 0 }, R = { -NOT, -NOT, -NOT, 0 }, ans;
			while (chain_number[t] != chain_number[u])
			{
				L = upt(get_max(1, 0, N - 1, section[chain_number[u]], section[u]), L);
				u = parent[chain_number[u]];
			}
			NODE temp = get_max(1, 0, N - 1, section[t] + 1, section[u]);
			L = upt(get_max(1, 0, N - 1, section[t] + 1, section[u]), L);
			while (chain_number[t] != chain_number[v])
			{
				R = upt(get_max(1, 0, N - 1, section[chain_number[v]], section[v]), R);
				v = parent[chain_number[v]];
			}
			R = upt(get_max(1, 0, N - 1, section[t], section[v]), R);
			swap(L.L_MAX, L.R_MAX);
			ans = upt(L, R);
			if (ans.T_MAX < 0)
				cout << 0 << '\n';
			else
				cout << ans.T_MAX << '\n';
		}
		else
		{
			cin >> w;
			int t = LCA(u, v);
			while (chain_number[t] != chain_number[u])
			{
				update(1, 0, N - 1, section[chain_number[u]], section[u], w);
				u = parent[chain_number[u]];
			}
			update(1, 0, N - 1, section[t] + 1, section[u], w);
			while (chain_number[t] != chain_number[v])
			{
				update(1, 0, N - 1, section[chain_number[v]], section[v], w);
				v = parent[chain_number[v]];
			}
			update(1, 0, N - 1, section[t], section[v], w);
		}
	}
}