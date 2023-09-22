#include <iostream>
#include <vector>
using namespace std;

int N, u, v, mx = 1;
vector <vector<int>> node;
vector <int> leaf;

void DFS(int n, int pn)
{
	if (node[n].size() != 1 || n == mx)
	{
		for (int x : node[n])
			if (x != pn)
				DFS(x, n);
	}
	else
		leaf.push_back(n);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node = vector<vector<int>>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, 0);

	if (node[1].size() == 1)
		leaf.push_back(1);

	int m = (leaf.size() + 1) / 2;
	cout << m << '\n';
	for (int i = 0; i < m; i++)
		cout << leaf[i] << ' ' << leaf[(i + m) % leaf.size()] << '\n';

	return 0;
}