#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, pair<int, int>>;

int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
string x;
vector<string> map;
vector <vector<int>> mx;
priority_queue <pii, vector<pii>, greater<pii>> pq;

void dijk()
{
	while (!pq.empty())
	{
		int Y = pq.top().second.first;
		int X = pq.top().second.second;
		int cnt = pq.top().first;
		pq.pop();
		if (mx[Y][X] < cnt)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int xx = X + dx[i];
			int yy = Y + dy[i];

			if (xx < 0 || xx >= M || yy < 0 || yy >= N)
				continue;

			if (map[yy][xx] == '0')
			{
				if (mx[yy][xx] > cnt)
				{
					mx[yy][xx] = cnt;
					pq.push(make_pair(cnt, make_pair(yy, xx)));
				}
			}
			else
			{
				if (mx[yy][xx] > cnt + 1)
				{
					mx[yy][xx] = cnt + 1;
					pq.push(make_pair(cnt + 1, make_pair(yy, xx)));
				}
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> M >> N;
	map = vector<string>(N);
	mx = vector<vector<int>>(N, vector<int>(M, 10001));

	for (int i = 0; i < N; i++)
		cin >> map[i];

	mx[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));
	dijk();

	cout << mx[N - 1][M - 1];

	return 0;
}