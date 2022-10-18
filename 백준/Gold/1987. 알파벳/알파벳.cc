#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <bool> check;
vector <vector<char>> map;
int N, M, mx = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int x, int y, int cnt)
{
	mx = max(mx, cnt);
	for (int i = 0; i < 4; i++)
	{
		int px = x + dx[i];
		int py = y + dy[i];
		if (py >= N || py < 0 || px >= M || px < 0 || check[map[py][px] - 'A'])
			continue;
		check[map[py][px] - 'A'] = true;
		DFS(px, py, cnt + 1);
		check[map[py][px] - 'A'] = false;
	}
}

int main(void)
{
	cin >> N >> M;
	map = vector<vector<char>>(N, vector<char>(M));
	check = vector<bool>(26, false);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	check[map[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	cout << mx;

	return 0;
}