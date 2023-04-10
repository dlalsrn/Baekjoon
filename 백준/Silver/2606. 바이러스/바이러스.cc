#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, cnt = 0;
vector <vector<int>> node;
vector <bool> check;

void DFS(int n)
{
	for (int x : node[n])
	{
		if (!check[x])
		{
			check[x] = true;
			cnt++;
			DFS(x);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	node = vector<vector<int>>(N + 1);
	check = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	check[1] = true;
	DFS(1);

	cout << cnt;

	return 0;
}