#include <iostream>
#include <vector>
using namespace std;

int N, h, u, v;
vector <vector<int>> node;
vector <int> leaf;

void DFS(int n, int pn)
{
	if (node[n].size() != 1 || n == 0)
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

	cin >> N >> h;

	node = vector<vector<int>>(N);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(0, -1);

	if (node[0].size() == 1)
		leaf.push_back(0);

	int m = (leaf.size() + 1) / 2;
	cout << m << '\n';
	for (int i = 0; i < m; i++)
		cout << leaf[i] << ' ' << leaf[(i + m) % leaf.size()] << '\n';

	return 0;
}