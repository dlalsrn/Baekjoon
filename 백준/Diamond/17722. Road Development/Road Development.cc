#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <vector<int>> node;
vector <int> segtree;
vector <int> lazy;
vector <int> parent_HLD;
vector <int> parent_SET;
vector <int> sz;
vector <int> depth;
vector <int> section;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
vector <pair<int, pair<int, int>>> com;
vector <bool> visit;
int N, M, cnt, ch, u, v;

void set_parent()
{
	for (int i = 1; i <= N; i++)
		parent_SET[i] = i;
}

int Find(int x)
{
	if (x == parent_SET[x])
		return x;
	return parent_SET[x] = Find(parent_SET[x]);
}
// parent_SET[x] = Find(parent_SET[x])
// 위 코드처럼 부모 노드를 갱신 안 시켜주면 부모를 찾는데 O(n)이므로 TLE 받음

bool Sameset(int x, int y)
{
	int px = Find(x);
	int py = Find(y);
	if (px == py)
		return true;
	else
		return false;
}

void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);
	if (px != py)
		parent_SET[px] = py;
}

void DFS(int n, int pn)
{
	visit[n] = true;
	parent_HLD[n] = pn;
	sz[n] = cnt++;
	for (int x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n];
}

void HLD(int n, int pn, int start_chain, int d)
{
	visit[n] = true;
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
			u = parent_HLD[chain_number[u]];
		else
			v = parent_HLD[chain_number[v]];
	}
	return chain_index[u] > chain_index[v] ? v : u;
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] != -1)
	{
		segtree[n] = (end - start + 1) * lazy[n];
		if (start != end)
		{
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = -1;
	}
}

void update(int n, int start, int end, int left, int right, int change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		segtree[n] = (end - start + 1) * change;
		if (start != end)
		{
			lazy[n * 2] = change;
			lazy[n * 2 + 1] = change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

int get_sum(int n, int start, int end, int left, int right)
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

	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 0);
	lazy = vector<int>((1 << (h + 1)), -1);
	node = vector<vector<int>>(N + 1);
	parent_HLD = vector<int>(N + 1);
	parent_SET = vector<int>(N + 1);
	section = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	set_parent();

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> u >> v;
		com.push_back(make_pair(ch, make_pair(u, v)));
		if (ch == 1)
		{
			if (!Sameset(u, v))
			{
				node[u].push_back(v);
				node[v].push_back(u);
				Union(u, v);
			}
		}
	}

	cnt = 0;
	visit = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
		if (!visit[i])
			DFS(i, 0);

	cnt = 0;
	visit = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
		if (!visit[i])
			HLD(i, 0, i, 0);

	set_parent();

	for (int i = 0; i < M; i++)
	{
		ch = com[i].first;
		u = com[i].second.first;
		v = com[i].second.second;
		if (ch == 1)
		{
			if (Sameset(u, v))
			{
				int t = LCA(u, v);
				while (chain_number[t] != chain_number[v])
				{
					update(1, 0, N - 1, section[chain_number[v]], section[v], 0);
					v = parent_HLD[chain_number[v]];
				}
				update(1, 0, N - 1, section[t] + 1, section[v], 0);
				while (chain_number[t] != chain_number[u])
				{
					update(1, 0, N - 1, section[chain_number[u]], section[u], 0);
					u = parent_HLD[chain_number[u]];
				}
				update(1, 0, N - 1, section[t] + 1, section[u], 0);
			}
			else
			{
				if (parent_HLD[u] != v)
					swap(u, v);
				update(1, 0, N - 1, section[u], section[u], 1);
				Union(u, v);
			}
		}
		else
		{
			if (Sameset(u, v))
			{
				int t = LCA(u, v);
				int sum = 0;
				while (chain_number[t] != chain_number[v])
				{
					sum += get_sum(1, 0, N - 1, section[chain_number[v]], section[v]);
					v = parent_HLD[chain_number[v]];
				}
				sum += get_sum(1, 0, N - 1, section[t] + 1, section[v]);
				while (chain_number[t] != chain_number[u])
				{
					sum += get_sum(1, 0, N - 1, section[chain_number[u]], section[u]);
					u = parent_HLD[chain_number[u]];
				}
				sum += get_sum(1, 0, N - 1, section[t] + 1, section[u]);
				cout << sum << '\n';
			}
			else
				cout << -1 << '\n';
		}

	}
	return 0;
}