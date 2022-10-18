#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define be(v) v.begin(), v.end()
using namespace std;
vector <vector<int>> segtree;
vector <vector<int>> node;
vector <pair<int, int>> T;
vector <int> parent;
vector <int> query;
vector <int> sz;
vector <int> depth;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int cnt, N, M;

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n].push_back(T[start].second);
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n].resize(segtree[n * 2].size() + segtree[n * 2 + 1].size());
		merge(be(segtree[n * 2]), be(segtree[n * 2 + 1]), segtree[n].begin());
	}
}

bool find(int n, int start, int end, int left, int right, int target)
{
	if (right < start || left > end)
		return false;
	if (left <= start && end <= right)
	{
		int index = lower_bound(be(segtree[n]), target) - segtree[n].begin();
		if (index == segtree[n].size())
			return false;
		return segtree[n][lower_bound(be(segtree[n]), target) - segtree[n].begin()] == target ? true : false;
	}
	return find(n * 2, start, (start + end) / 2, left, right, target) || find(n * 2 + 1, (start + end) / 2 + 1, end, left, right, target);
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

	query[n] = cnt;
	T[cnt++].second = T[n].first;
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

int LCA(int x, int y)
{
	while (chain_number[x] != chain_number[y])
	{
		if (depth[x] > depth[y])
			x = parent[chain_number[x]];
		else
			y = parent[chain_number[y]];
	}
	return chain_index[x] > chain_index[y] ? y : x;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, c;
	string total = "";
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<vector<int>>((1 << (h + 1)));
	node = vector<vector<int>>(N + 1);
	T = vector<pair<int, int>>(N + 1);
	parent = vector<int>(N + 1);
	sz = vector<int>(N + 1);
	query = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> T[i].first;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);
	set_segtree(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> c;
		bool ans = false;
		int t = LCA(x, y);
		while (chain_number[t] != chain_number[x])
		{
			ans |= find(1, 0, N - 1, query[chain_number[x]], query[x], c);
			x = parent[chain_number[x]];
		}
		ans |= find(1, 0, N - 1, query[t], query[x], c);
		while (chain_number[t] != chain_number[y])
		{
			ans |= find(1, 0, N - 1, query[chain_number[y]], query[y], c);
			y = parent[chain_number[y]];
		}
		ans |= find(1, 0, N - 1, query[t], query[y], c);
		if (ans)
			total += '1';
		else
			total += '0';
	}
	cout << total;
	return 0;
}