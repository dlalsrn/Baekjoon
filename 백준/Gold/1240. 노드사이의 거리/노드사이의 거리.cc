#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, M, u, v, c;
bool check;
vector <vector<pi>> node;

void DFS(int pn, int n, int cnt)
{
	if (n == v)
	{
		cout << cnt << '\n';
		check = false;
		return;
	}

	for (pi x : node[n])
		if (x.first != pn && check)
			DFS(n, x.first, cnt + x.second);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	node.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> c;
		node[u].emplace_back(v, c);
		node[v].emplace_back(u, c);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		check = true;
		DFS(-1, u, 0);
	}

	return 0;
}