#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001
using namespace std;

vector <vector<int>> node;
int N, M, u, v, w;

void Floyd()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (node[i][k] != INF && node[k][j] != INF)
					node[i][j] = min(node[i][j], node[i][k] + node[k][j]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	node = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u][v] = min(node[u][v], w);
	}

	Floyd();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				cout << 0 << ' ';
			else
				cout << (node[i][j] != INF ? node[i][j] : 0) << ' ';
		}
		cout << '\n';
	}

	return 0;
}