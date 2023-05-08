#include <iostream>
#include <vector>
using namespace std;

int N, u, v;
vector <vector<int>> node;
vector <int> parent;

void DFS(int n, int pn)
{
	parent[n] = pn;
	for (int x : node[n])
		if (x != pn)
			DFS(x, n);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	node.resize(N + 1);
	parent.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, -1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}