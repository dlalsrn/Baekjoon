#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, K, L, X, x, y, cnt = 0, k = 0, pre = 0;
char C;
bool die = false;
queue <pi> q;
vector <vector<bool>> apple;
vector <vector<bool>> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N >> K;

	apple = vector<vector<bool>>(N, vector<bool>(N, false));
	m = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		apple[y - 1][x - 1] = true;
	}

	cin >> L;
	y = x = 0;
	q.push(make_pair(0, 0));
	m[0][0] = true;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		if (die) continue;
		for (int j = 0; j < X - pre; j++)
		{
			y += dy[k];
			x += dx[k];

			if (y >= N || y < 0 || x >= N || x < 0 || m[y][x])
			{
				cnt++;
				die = true;
				break;
			}

			m[y][x] = true;
			if (apple[y][x]) apple[y][x] = false;
			else
			{
				int yy = q.front().first;
				int xx = q.front().second;
				q.pop();
				m[yy][xx] = false;
			}
			q.push(make_pair(y, x));
			cnt++;
		}

		if (die) continue;
		pre = X;
		k = (C == 'L' ? k + 3 : k + 1) % 4;
	}

	if (!die)
	{
		while (true)
		{
			y += dy[k];
			x += dx[k];

			if (y >= N || y < 0 || x >= N || x < 0 || m[y][x])
			{
				cnt++;
				break;
			}

			m[y][x] = true;
			if (apple[y][x]) apple[y][x] = false;
			else
			{
				int yy = q.front().first;
				int xx = q.front().second;
				q.pop();
				m[yy][xx] = false;
			}
			q.push(make_pair(y, x));
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}