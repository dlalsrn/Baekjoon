#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, cnt = 0;
vector <vector<int>> node;
vector <bool> visit;

void DFS(int n)
{
	visit[n] = true;
    
	for (int x : node[n])
		if (!visit[x])
			DFS(x);
}

int main(void)
{
	cin >> N >> M;

	node = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			cnt++;
			DFS(i);
		}
	}

	cout << cnt;

	return 0;
}