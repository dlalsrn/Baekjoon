#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ppii = pair<int, pair<int, int>>; // { value, { point }}

vector <vector<char>> map;
vector <vector<int>> check;
queue <ppii> q;
pair<int, int> start, finish; // y, x
int N, M;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

void dijk()
{
	while (!q.empty())
	{
		int Y = q.front().second.first;
		int X = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (check[Y][X] < cnt)
			continue;
		if (finish == make_pair(Y, X))
			continue;

		for (int k = 0; k < 8; k++)
		{
			int xx = X + dx[k];
			int yy = Y + dy[k];

			if (xx < 0 || yy < 0 || xx >= M || yy >= N || map[yy][xx] == '#')
				continue;

			if (xx == X + 1)
			{
				if (check[yy][xx] != -1 && check[yy][xx] <= cnt)
					continue;
				check[yy][xx] = cnt;
				q.push(make_pair(cnt, make_pair(yy, xx)));
			}
			else
			{
				if (check[yy][xx] != -1 && check[yy][xx] <= cnt + 1)
					continue;
				check[yy][xx] = cnt + 1;
				q.push(make_pair(cnt + 1, make_pair(yy, xx)));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	map = vector<vector<char>>(N, vector<char>(M));
	check = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				finish = make_pair(i, j);
			else if (map[i][j] == 'K')
				start = make_pair(i, j);
		}
	}

	check[start.first][start.second] = 0;
	q.push(make_pair(0, start));

	dijk();

	cout << check[finish.first][finish.second];

	return 0;
}