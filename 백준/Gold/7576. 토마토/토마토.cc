#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int main(void)
{
	int M, N, i, j, cnt = 0;
	bool TF[1000][1000];
	int tmt[1000][1000];
	queue <pair<int, pair<int, int>>> q;
	cin >> M >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> tmt[i][j];
			if (tmt[i][j] == 1)
			{
				TF[i][j] = true;
				q.push({ 0, {i,j} });
			}
			else
				TF[i][j] = false;
		}
	}
	//cout << q.size();
	pair <int, pair<int, int>> temp;
	while (!q.empty())
	{
		temp = q.front();
		i = temp.second.first;
		j = temp.second.second;
		cnt = temp.first;
		q.pop();

		if (i + 1 < N && TF[i + 1][j] == false && tmt[i + 1][j] == 0)
		{
			TF[i + 1][j] = true;
			tmt[i + 1][j] = 1;
			q.push({ cnt + 1, { i + 1, j } });
		}
		if (i - 1 >= 0 && TF[i - 1][j] == false && tmt[i - 1][j] == 0)
		{
			TF[i - 1][j] = true;
			tmt[i - 1][j] = 1;
			q.push({ cnt + 1, { i - 1, j } });
		}
		if (j + 1 < M && TF[i][j + 1] == false && tmt[i][j + 1] == 0)
		{
			TF[i][j + 1] = true;
			tmt[i][j + 1] = 1;
			q.push({ cnt + 1,{ i, j + 1 } });
		}
		if (j - 1 >= 0 && TF[i][j - 1] == false && tmt[i][j - 1] == 0)
		{
			TF[i][j - 1] = true;
			tmt[i][j - 1] = 1;
			q.push({ cnt + 1, {i, j - 1 } });
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (TF[i][j] == false && tmt[i][j] != -1)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
	return 0;
}