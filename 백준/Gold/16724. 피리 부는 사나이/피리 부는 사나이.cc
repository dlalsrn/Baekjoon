#include <bits/stdc++.h>
using namespace std;

int N, M, cnt = 0, ans = 0;
vector <vector<char>> v;
vector <vector<int>> check;

void DFS(int y, int x)
{
	char t = v[y][x];
	int yy = y;
	int xx = x;

	if (t == 'D') yy++;
	else if (t == 'R') xx++;
	else if (t == 'U') yy--;
	else xx--;

	if (check[yy][xx] == -1)
	{
		check[yy][xx] = cnt;
		DFS(yy, xx);
	}
	else
	{
		if (cnt == check[yy][xx]) ans++;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	v = vector<vector<char>>(N, vector<char>(M));
	check = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == -1)
			{
				check[i][j] = cnt;
				DFS(i, j);
				cnt++;
			}
		}
	}

	cout << ans;

	return 0;
}