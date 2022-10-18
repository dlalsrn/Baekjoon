#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char board[1001][1001];
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0,0,1,-1 };
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pair<int, int> score[10] = { {0, 0} };
	// first는 거리, second 는 성의 갯수
	int N, M, P, dis, size = 0;
	cin >> N >> M >> P;
	vector <queue<pair<int, int>>> v(P+1);
	for (int i = 1; i <= P; i++)
	{
		cin >> dis;
		score[i] = { dis, 0 };
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != '.' && board[i][j] != '#')
			{
				size++;
				pq.push({ board[i][j] - '0', {j, i} }); // x, y
				score[board[i][j] - '0'].second++;
			}
		}
	}
	while (!pq.empty())
	{
		v[pq.top().first].push(pq.top().second);
		pq.pop();
	}

	int turn = 1;
	while (size > 0)
	{
		if (v[turn].size() == 0)
		{
			turn++;
			if (turn == P + 1)
				turn = 0;
		}
		for (int i = 0; i < score[turn].first; i++)
		{
			if (v[turn].size() == 0)
				break;
			int len = v[turn].size();

			while (len--)
			{
				for (int j = 0; j < 4; j++)
				{
					int x = v[turn].front().first + dx[j];
					int y = v[turn].front().second + dy[j];
					if (x > M || x < 1)
						continue;
					if (y > N || y < 1)
						continue;
					if (board[y][x] == '.')
					{
						v[turn].push({ x, y });
						board[y][x] = turn + '0';
						score[turn].second++;
						size++;
					}
				}
				v[turn].pop();
				size--;
			}
		}
		turn++;
		if (turn == P + 1)
			turn = 0;
	}

	for (int i = 1; i <= P; i++)
		cout << score[i].second << ' ';
	return 0;
}