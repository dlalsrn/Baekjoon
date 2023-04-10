#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, start, u, v;
vector <vector<int>> node;
vector <bool> check;
queue <int> q;

void DFS(int n)
{
	cout << n << ' ';
	for (int x : node[n])
	{
		if (!check[x])
		{
			check[x] = true;
			DFS(x);
		}
	}
}

void BFS()
{
	while (!q.empty())
	{
		cout << q.front() << ' ';
		int n = q.front();
		q.pop();

		for (int x : node[n])
		{
			if (!check[x])
			{
				check[x] = true;
				q.push(x);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> start;

	node = vector<vector<int>>(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(node[i].begin(), node[i].end());

	check = vector<bool>(N + 1, false);
	check[start] = true;
	DFS(start);
	cout << '\n';

	check = vector<bool>(N + 1, false);
	check[start] = true;
	q.push(start);
	BFS();

	return 0;
}