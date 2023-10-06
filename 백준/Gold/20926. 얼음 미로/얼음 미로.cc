#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
using pii = pair<int, pi>;

int N, M, mn = 1e9;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector <vector<char>> map;
vector <vector<bool>> visit;
priority_queue <pii, vector<pii>, greater<pii>> q;
pi start, finish;

void BFS()
{
	while (!q.empty())
	{
		int x = q.top().second.second;
		int y = q.top().second.first;
		int cost = q.top().first;
		q.pop();

		if (visit[y][x])
			continue;
		visit[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= M || yy < 0 || yy >= N || map[yy][xx] == 'R' || map[yy][xx] == 'H')
				continue;
			if (map[yy][xx] == 'E')
			{
				mn = min(mn, cost);
				continue;
			}

			int cnt = 0;
			while (true)
			{
				if (map[yy][xx] != 'T')
					cnt += (map[yy][xx] - '0');
				if (xx + dx[i] < 0 || xx + dx[i] >= M || yy + dy[i] < 0 || yy + dy[i] >= N || map[yy + dy[i]][xx + dx[i]] == 'H') // 절벽이거나 구멍
					break;
				else if (map[yy + dy[i]][xx + dx[i]] == 'R')
				{
					if (!visit[yy + dy[i]][xx + dx[i]])
						q.push(make_pair(cnt + cost, make_pair(yy, xx)));
					break;
				}
				else if (map[yy + dy[i]][xx + dx[i]] == 'E')
				{
					mn = min(mn, cost + cnt);
					break;
				}
				xx += dx[i];
				yy += dy[i];
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> M >> N;

	map = vector<vector<char>>(N, vector<char>(M));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'T')
				start = make_pair(i, j);
			if (map[i][j] == 'E')
				finish = make_pair(i, j);
		}
	}

	q.push(make_pair(0, start));

	BFS();

	cout << (mn == 1e9 ? -1 : mn);

	return 0;
}