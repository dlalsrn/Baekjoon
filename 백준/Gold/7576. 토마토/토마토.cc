#include <bits/stdc++.h>
using namespace std;

int N, M, x, mx = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector <vector<int>> m;
vector <vector<bool>> check;
queue <pair<pair<int, int>, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		mx = max(mx, cnt);

		for (int k = 0; k < 4; k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || xx >= M || yy < 0 || yy >= N || check[yy][xx] || m[yy][xx] == -1)
				continue;
			check[yy][xx] = true;
			q.push(make_pair(make_pair(yy, xx), cnt + 1));
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> M >> N;

	m.resize(N, vector<int>(M));
	check.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 1)
			{
				q.push(make_pair(make_pair(i, j), 0));
				check[i][j] = true;
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j] && m[i][j] != -1)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << mx;

	return 0;
}