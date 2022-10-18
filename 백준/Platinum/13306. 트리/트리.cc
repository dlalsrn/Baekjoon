// 트리
// 22.07.25
// a에서 b로 가는 길이 이어져있나 끊어져 있나 확인하는 문제
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> node;
vector <int> segtree;
vector <int> section;
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
	sz[n] = cnt++;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn)
			DFS(node[n][i], n);
	sz[n] = cnt - sz[n];
}

void HLD(int n, int pn, int start_chain, int d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	int heavy = -1;
	section[n] = cnt++;
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
	int p, ch, u, v;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 1); // 처음엔 모두 연결돼있으므로 1로 초기화
	section = vector<int>(N + 1);
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

	// 노드 a, b가 있을 때 자식 노드가 edge 값을 가지고 있음
	for (int i = 0; i < N + M - 1; i++)
	{
		cin >> ch >> u;

		if (ch == 0)
			update(1, 0, N - 1, section[u]);
		else
		{
			cin >> v;
			int mn = 1;
			int t = LCA(u, v);
			// 구간에서 길이 끊겨있다면 get_min이 0을 반환함
			while (chain_number[t] != chain_number[u])
			{
				mn = min(mn, get_min(1, 0, N - 1, section[chain_number[u]], section[u]));
				u = parent[chain_number[u]];
			}
			mn = min(mn, get_min(1, 0, N - 1, section[t] + 1, section[u]));
			while (chain_number[t] != chain_number[v])
			{
				mn = min(mn, get_min(1, 0, N - 1, section[chain_number[v]], section[v]));
				v = parent[chain_number[v]];
			}
			mn = min(mn, get_min(1, 0, N - 1, section[t] + 1, section[v]));
			// t는 t의 부모와의 edge값을 가지고 있으므로 포함하면 안 됨. 범위에서 제외

			if (mn == 0)
				cout << "NO" << '\n';
			else
				cout << "YES" << '\n';
		}
	}
}