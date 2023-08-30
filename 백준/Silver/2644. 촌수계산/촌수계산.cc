#include <iostream>
#include <vector>
using namespace std;

int N, M, X, Y, u, v;
vector <vector<int>> node;
vector <int> mx_dis;
vector <bool> visit;
bool TF = true;

void DFS(int n, int cnt)
{
	if (n == Y)
	{
		cout << cnt;
		TF = false;
		return;
	}
	for (int x : node[n])
	{
		if (!visit[x])
		{
			visit[x] = true;
			DFS(x, cnt + 1);
		}
	}
}

int main(void)
{
	cin >> N;

	node = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1, false);
	cin >> X >> Y >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	visit[X] = true;
	DFS(X, 0);

	if (TF)
		cout << -1;

	return 0;
}