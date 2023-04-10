#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
string x;
vector <string> map;
vector <vector<bool>> check;
queue <pair<int, pair<int, int>>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS()
{
	while (!q.empty())
	{
		int y = q.front().second.first;
		int x = q.front().second.second;
		int c = q.front().first;
		if (y == N - 1 && x == M - 1)
		{
			cout << c;
			q = queue <pair<int, pair<int, int>>>();
			continue;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy < 0 || xx < 0 || xx >= M || yy >= N || check[yy][xx] || map[yy][xx] == '0')
				continue;

			check[yy][xx] = true;
			q.push(make_pair(c + 1, make_pair(yy, xx)));
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
		map.push_back(x);
	}

	q.push(make_pair(1, make_pair(0, 0)));
	check[0][0] = true;

	BFS();

	return 0;
}