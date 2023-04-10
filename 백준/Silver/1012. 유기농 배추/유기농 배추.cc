#include <iostream>
#include <vector>
using namespace std;

int T, N, M, K, cnt, X, Y;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector <vector<int>> map;
vector <vector<bool>> check;

void DFS(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int xx = j + dx[k];
		int yy = i + dy[k];
		if (xx < 0 || xx >= M || yy < 0 || yy >= N || check[yy][xx] || map[yy][xx] != 1)
			continue;
		check[yy][xx] = true;
		DFS(yy, xx);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		
		cnt = 0;
		map = vector<vector<int>>(N, vector<int>(M, 0));
		check = vector<vector<bool>>(N, vector<bool>(M, false));

		for (int k = 0; k < K; k++)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!check[i][j] && map[i][j] == 1)
					check[i][j] = true, DFS(i, j), cnt++;

		cout << cnt << '\n';
	}

	return 0;
}