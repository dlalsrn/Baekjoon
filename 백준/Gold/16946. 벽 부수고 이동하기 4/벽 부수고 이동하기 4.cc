#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <vector<int>> map;
vector <vector<int>> total; // 최종 맵
vector <pair<int, int>> order; // map에 있는 0이 있는 위치
vector <vector<bool>> visit; // 맵에서 방문한 0들
vector <vector<bool>> visit_one; // 특정 구격에서 방문한 1의 위치
vector <pair<int, int>> spec_one; // 특정 구역에 있는 1의 위치
int N, M, cnt;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DFS(int x, int y)
{
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int px = x + dx[i];
		int py = y + dy[i];
		if (px >= M || px < 0 || py >= N || py < 0)
			continue;
		if (map[py][px] == 1 && !visit_one[py][px])
		{
			spec_one.push_back(make_pair(py, px));
			visit_one[py][px] = true;
		}
		if (map[py][px] == 1 || visit[py][px])
			continue;
		visit[py][px] = true;
		DFS(px, py);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x;
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	total = vector<vector<int>>(N, vector<int>(M, 0));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	visit_one = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = x[j] - '0';
			if (map[i][j] == 0)
				order.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < order.size(); i++)
	{
		int y = order[i].first;
		int x = order[i].second;
		if (visit[y][x])
			continue;
		cnt = 0;
		visit[y][x] = true;
		spec_one = vector<pair<int, int>>();
		DFS(x, y);
		for (int j = 0; j < spec_one.size(); j++)
		{
			total[spec_one[j].first][spec_one[j].second] += cnt;
			visit_one[spec_one[j].first][spec_one[j].second] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
				cout << (total[i][j] + 1) % 10;
			else
				cout << 0;
		}
		cout << '\n';
	}

	return 0;
}