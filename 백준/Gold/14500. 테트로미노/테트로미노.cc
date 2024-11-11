#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, M, ans = 0;
vector <vector<int>> v;
vector <vector<bool>> check;

void DFS(int y, int x, int sum, int cnt)
{
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx < 0 || yy < 0 || xx >= M || yy >= N || check[yy][xx]) continue;

		check[yy][xx] = true;
		DFS(yy, xx, sum + v[yy][xx], cnt + 1);
		check[yy][xx] = false;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	v = vector<vector<int>>(N, vector<int>(M));
	check = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = true;
			DFS(i, j, v[i][j], 1);
			check[i][j] = false;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j - 1 >= 0 && j + 1 < M && i + 1 < N) { // ㅜ
				ans = max(ans, v[i][j - 1] + v[i][j] + v[i][j + 1] + v[i + 1][j]);
			}
			if (j - 1 >= 0 && j + 1 < M && i - 1 >= 0) { // ㅗ
				ans = max(ans, v[i][j - 1] + v[i][j] + v[i][j + 1] + v[i - 1][j]);
			}
			if (i - 1 >= 0 && i + 1 < N && j - 1 >= 0) { // ㅓ
				ans = max(ans, v[i - 1][j] + v[i][j] + v[i + 1][j] + v[i][j - 1]);
			}
			if (i - 1 >= 0 && i + 1 < N && j + 1 < M) { // ㅏ
				ans = max(ans, v[i - 1][j] + v[i][j] + v[i + 1][j] + v[i][j + 1]);
			}
		}
	}

	cout << ans;

	return 0;
}