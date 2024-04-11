#include <bits/stdc++.h>
using namespace std;

int N, u, v, sum = 0;
vector <vector<int>> node;

void DFS(int pn, int n, int cnt)
{
	if (n != 1 && node[n].size() == 1)
	{
		sum += cnt;
		return;
	}

	for (int x : node[n])
		if (x != pn)
			DFS(n, x, cnt + 1);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	
	DFS(-1, 1, 0);

	cout << (sum % 2 ? "Yes" : "No");

	return 0;
}