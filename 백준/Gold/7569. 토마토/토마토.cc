// 3차원 토마토
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int M, N, H, i, j, k, cnt = 0;
	bool TF[100][100][100];
	int tmt[100][100][100];
	queue <pair<int, pair<int, pair<int, int>>>> q;
	cin >> M >> N >> H;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
			{
				cin >> tmt[i][j][k];
				if (tmt[i][j][k] == 1)
				{
					TF[i][j][k] = true;
					q.push({ 0, {i, {j,k}} });
				}
				else
					TF[i][j][k] = false;
			}
		}
	}
	pair <int, pair<int, pair<int, int>>> temp;
	while (!q.empty())
	{
		temp = q.front();
		i = temp.second.first;
		j = temp.second.second.first;
		k = temp.second.second.second;
		cnt = temp.first;
		q.pop();

		if (i + 1 < H && TF[i + 1][j][k] == false && tmt[i + 1][j][k] == 0)
		{
			TF[i + 1][j][k] = true;
			tmt[i + 1][j][k] = 1;
			q.push({ cnt + 1, { i + 1, {j,k } } });
		}
		if (i - 1 >= 0 && TF[i - 1][j][k] == false && tmt[i - 1][j][k] == 0)
		{
			TF[i - 1][j][k] = true;
			tmt[i - 1][j][k] = 1;
			q.push({ cnt + 1, { i - 1, {j,k} } });
		}
		if (j + 1 < N && TF[i][j + 1][k] == false && tmt[i][j + 1][k] == 0)
		{
			TF[i][j + 1][k] = true;
			tmt[i][j + 1][k] = 1;
			q.push({ cnt + 1,{ i, {j + 1, k }} });
		}
		if (j - 1 >= 0 && TF[i][j - 1][k] == false && tmt[i][j - 1][k] == 0)
		{
			TF[i][j - 1][k] = true;
			tmt[i][j - 1][k] = 1;
			q.push({ cnt + 1, {i, {j - 1,k} } });
		}
		if (k + 1 < M && TF[i][j][k + 1] == false && tmt[i][j][k + 1] == 0)
		{
			TF[i][j][k+1] = true;
			tmt[i][j][k+1] = 1;
			q.push({ cnt + 1, {i, {j,k+1} } });
		}
		if (k - 1 >= 0 && TF[i][j][k - 1] == false && tmt[i][j][k - 1] == 0)
		{
			TF[i][j][k - 1] = true;
			tmt[i][j][k - 1] = 1;
			q.push({ cnt + 1, {i, {j,k - 1} } });
		}
	}

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < M; k++)
			{
				if (TF[i][j][k] == false && tmt[i][j][k] != -1)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}