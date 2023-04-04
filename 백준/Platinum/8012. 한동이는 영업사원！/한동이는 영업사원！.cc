#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, u, v, sum = 0, last;
vector <vector<int>> node;
vector <vector<int>> parent;
vector <int> depth;

void DFS(int pn, int n)
{
	for (int x : node[n])
	{
		if (x != pn)
		{
			depth[x] = depth[n] + 1;
			parent[0][x] = n;
			DFS(n, x);
		}
	}
}

int LCA(int u, int v)
{
	for (int i = floor(log2(N)); i >= 0; i--)
	{
		if (parent[i][u] != parent[i][v])
		{
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	if (u == v)
		return u;
	return parent[0][u];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	node = vector<vector<int>>(N + 1);
	parent = vector<vector<int>>(floor(log2(N)) + 1, vector<int>(N + 1, -1));
	depth = vector<int>(N + 1, -1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	
	depth[1] = 0;
	parent[0][1] = -1;
	DFS(0, 1);

	for (int i = 1; i <= floor(log2(N)); i++)
		for (int j = 1; j <= N; j++)
			if (parent[i-1][j] != -1)
				parent[i][j] = parent[i - 1][parent[i - 1][j]];

	cin >> M;
	last = 1;
	for (int i = 0; i < M; i++)
	{
		cin >> u;
		int s = u;
		if (i == 0)
			sum += depth[u];
		else
		{
			sum += depth[last] + depth[u];

			if (depth[u] < depth[last])
				swap(u, last);
			int diff = depth[u] - depth[last];

			for (int j = 0; diff; j++, diff >>= 1)
				if (diff & 1)
					u = parent[j][u];

			int t = LCA(u, last);
			sum -= depth[t] * 2;
		}
		last = s;
	}

	cout << sum;
	return 0;
}