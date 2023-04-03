#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> node;
vector <int> sz;
vector <int> parent;
vector <int> depth;
vector <int> D;
vector <int> chain_number;
vector <int> chain_index;
vector <vector<int>> chain;
int N, M, u, v, root, cnt = 0;

void DFS(int n, int pn)
{
	parent[n] = pn;
	D[n] = D[pn] + 1;
	sz[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn)
			DFS(node[n][i], n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int cur_chain, int d)
{
	depth[n] = d;
	chain_number[n] = cur_chain;
	chain_index[n] = chain[cur_chain].size();
	chain[cur_chain].push_back(n);

	int heavy = -1;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn && (heavy == -1 || sz[node[n][i]] > sz[heavy]))
			heavy = node[n][i];

	if (heavy != -1)
		HLD(heavy, n, cur_chain, d);

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn && node[n][i] != heavy)
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	node = vector<vector<int>>(N + 1);
	sz = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	depth = vector<int>(N + 1);
	D = vector<int>(N + 1, -1);
	chain_number = vector<int>(N + 1);
	chain_index = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, 0);
	HLD(1, 0, 1, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> root >> u >> v;
		int lca_u = LCA(root, u);
		int lca_v = LCA(root, v);
		int lca_root = LCA(u, v);
		if (D[lca_u] > D[lca_v] && D[lca_u] > D[lca_root])
			cout << lca_u << '\n';
		else if (D[lca_v] > D[lca_u] && D[lca_v] > D[lca_root])
			cout << lca_v << '\n';
		else
			cout << lca_root << '\n';
		/*
		if (D[root] < D[u] && D[root] < D[v])
			cout << LCA(u, v) << '\n';
		else if (D[root] > D[u] && D[root] > D[v])
		{
			int lca_u = LCA(root, u);
			int lca_v = LCA(root, v);
			cout << (D[lca_u] > D[lca_v] ? lca_u : lca_v) << '\n';
		}
		else
		{
			int lca_u = LCA(root, u);
			int lca_v = LCA(root, v);
			int lca_root = LCA(u, v);
			if (D[lca_u] > D[lca_v] && D[lca_u] > D[lca_root])
				cout << lca_u << '\n';
			else if (D[lca_v] > D[lca_u] && D[lca_v] > D[lca_root])
				cout << lca_v << '\n';
			else
				cout << lca_root << '\n';
		}
		*/
	}

	return 0;
}