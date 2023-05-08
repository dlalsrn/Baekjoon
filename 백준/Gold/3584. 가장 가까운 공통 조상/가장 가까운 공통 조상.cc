#include <iostream>
#include <vector>
using namespace std;

int T, N, u, v, root;
vector <vector<int>> node;
vector <int> parent;
vector <int> depth;

void DFS(int n, int d)
{
	depth[n] = d;
	for (int x : node[n])
		DFS(x, d + 1);
}

int LCA(int u, int v)
{
	while (u != v)
	{
		if (depth[u] > depth[v])
			u = parent[u];
		else
			v = parent[v];
	}
	return u;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		
		parent = vector<int>(N + 1, -1);
		depth = vector<int>(N + 1);
		node = vector<vector<int>>(N + 1);

		for (int i = 0; i < N - 1; i++)
		{
			cin >> u >> v;
			node[u].push_back(v);
			parent[v] = u;
		}

		for (int i = 1; i <= N; i++)
		{
			if (parent[i] == -1)
			{
				root = i;
				break;
			}
		}

		DFS(root, 0);

		cin >> u >> v;
		int lca = LCA(u, v);

		cout << lca << '\n';
	}

	return 0;
}