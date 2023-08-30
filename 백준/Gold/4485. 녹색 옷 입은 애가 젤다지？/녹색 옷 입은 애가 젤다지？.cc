// 녹색 옷 입은 애가 젤다지?
// 23.08.30
// 다익스트라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, pair<int, int>>;

int T, N, t = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
string x;
vector <vector<int>> map;
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

			if (xx < 0 || xx >= N || yy < 0 || yy >= N)
				continue;

			if (mx[yy][xx] > cnt + map[yy][xx])
			{
				mx[yy][xx] = cnt + map[yy][xx];
				pq.push(make_pair(mx[yy][xx], make_pair(yy, xx)));
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while(cin >> N)
	{
		if (N == 0)
			break;
		map = vector<vector<int>>(N, vector<int>(N));
		mx = vector<vector<int>>(N, vector<int>(N, 100000));
		pq = priority_queue <pii, vector<pii>, greater<pii>>();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		mx[0][0] = map[0][0];
		pq.push(make_pair(map[0][0], make_pair(0, 0)));
		dijk();

		cout << "Problem " << ++t << ": " << mx[N - 1][N - 1] << '\n';
	}

	return 0;
}