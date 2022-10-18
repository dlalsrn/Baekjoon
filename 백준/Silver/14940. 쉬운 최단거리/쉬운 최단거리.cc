#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ary[1000][1000];
	int total[1000][1000] = { 0 };
	bool TF[1000][1000];
	int N, M;
	queue <pair<int, pair<int, int>>> q;
	pair <int, int> start;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> ary[i][j];
			if (ary[i][j] == 2)
			{
				ary[i][j] = 0;
				start = { i, j };
			}
			TF[i][j] = false;
		}
	}
	q.push({ 0, {start} });

	while (!q.empty())
	{
		pair<int, pair<int, int>> temp = q.front();
		q.pop();
		int i = temp.second.first;
		int j = temp.second.second;
		int cnt = temp.first;

		if (i + 1 < N && TF[i + 1][j] == false && ary[i + 1][j] != 0)
		{
			q.push({ cnt + 1, {i + 1, j} });
			ary[i + 1][j] = cnt + 1;
			TF[i + 1][j] = true;
		}
		if (i - 1 >= 0 && TF[i - 1][j] == false && ary[i - 1][j] != 0)
		{
			q.push({ cnt + 1, {i - 1, j} });
			ary[i - 1][j] = cnt + 1;
			TF[i - 1][j] = true;
		}
		if (j + 1 < M && TF[i][j + 1] == false && ary[i][j + 1] != 0)
		{
			q.push({ cnt + 1, {i, j + 1} });
			ary[i][j + 1] = cnt + 1;
			TF[i][j + 1] = true;
		}
		if (j - 1 >= 0 && TF[i][j - 1] == false && ary[i][j - 1] != 0)
		{
			q.push({ cnt + 1, {i, j - 1} });
			ary[i][j - 1] = cnt + 1;
			TF[i][j - 1] = true;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (TF[i][j] == false && ary[i][j] == 1)
				cout << -1 << ' ';
			else
				cout << ary[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}