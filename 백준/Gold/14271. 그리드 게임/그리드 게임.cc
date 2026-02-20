#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int N, M, K;
int cnt = 0;
vector<vector<bool>> check;
queue<pi> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	check = vector<vector<bool>>(4000, vector<bool>(4000, false));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			cin >> c;
			if (c == 'o')
			{
				++cnt;
				check[2000 + i][2000 + j] = true;
				q.push(make_pair(2000 + i, 2000 + j));
			}
		}
	}

	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int sz = q.size();

		for (int j = 0; j < sz; ++j)
		{
			auto [y, x] = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int yy = y + dy[k];
				int xx = x + dx[k];

				if (yy < 0 || yy >= 4000 || xx < 0 || xx >= 4000 || check[yy][xx]) continue;

				++cnt;
				check[yy][xx] = true;
				q.push(make_pair(yy, xx));
			}
		}
	}

	cout << cnt << '\n';
}