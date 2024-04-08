#include <bits/stdc++.h>
using namespace std;

int N, M;
string x;
vector <string> m;
vector <vector<bool>> check;
queue <pair<pair<int, int>, int>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs()
{
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1)
		{
			cout << c;
			return;
		}

		for (int k = 0; k < 4; k++)
		{
			int yy = y + dy[k];
			int xx = x + dx[k];

			if (yy < 0 || xx < 0 || xx >= M || yy >= N || check[yy][xx] || m[yy][xx] == '0')
				continue;

			check[yy][xx] = true;
			q.push(make_pair(make_pair(yy, xx), c + 1));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	check = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		m.push_back(x);
	}

	check[0][0] = true;
	q.push(make_pair(make_pair(0, 0), 1));

	bfs();

	return 0;
}