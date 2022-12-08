#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

vector <vector<int>> map;
vector <vector<int>> dp;
vector <vector<bool>> row_wall;
vector <vector<bool>> col_wall;

int N, M;
int X1, X2, Y1, Y2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	dp = vector<vector<int>>(N, vector<int>(M, INF));
	row_wall = vector<vector<bool>>(N, vector<bool>(M, false));
	col_wall = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cin >> Y1 >> X1 >> Y2 >> X2;

	if ((Y1 == Y2 && 0 < Y1 && Y1 < N && X1 == 0 && X2 == M) || (X1 == X2 && 0 < X1 && X1 < M && Y1 == 0 && Y2 == N))
		cout << "Entity";
	else
	{
		if (Y1 == Y2 && (Y1 != 0 && Y1 != N))
		{
			if (X1 > X2)
				swap(X1, X2);
			for (int i = X1; i < X2; i++)
				row_wall[Y1][i] = true;
		}
		else if (X1 == X2 && (X1 != 0 && X1 != M))
		{
			if (Y1 > Y2)
				swap(Y1, Y2);
			for (int i = Y1; i < Y2; i++)
				col_wall[i][X1] = true;
		}

		dp[0][0] = map[0][0];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (dp[i][j] == INF)
					continue;
				if (j + 1 < M && !col_wall[i][j + 1])
				{
					if (dp[i][j + 1] == INF)
						dp[i][j + 1] = dp[i][j] + map[i][j + 1];
					else
						dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + map[i][j + 1]);
				}
				if (i + 1 < N && !row_wall[i + 1][j])
				{
					if (dp[i + 1][j] == INF)
						dp[i + 1][j] = dp[i][j] + map[i + 1][j];
					else
						dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + map[i + 1][j]);
				}
			}
		}

		cout << dp[N - 1][M - 1];
	}

	return 0;
}