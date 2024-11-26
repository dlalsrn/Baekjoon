#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int X, Y, N, M, cnt = 0;
string x;
vector <string> m;
vector <vector<bool>> check;

void dfs(int y, int x) {
	for (int k = 0; k < 4; k++) {
		int yy = y + dy[k];
		int xx = x + dx[k];

		if (yy < 0 || yy >= N || xx < 0 || xx >= M || m[yy][xx] == 'X' || check[yy][xx]) continue;

		if (m[yy][xx] == 'P') cnt++;
		check[yy][xx] = true;
		dfs(yy, xx);
	}
}
int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	check = vector<vector<bool>>(N, vector<bool>(M, false));
	m = vector<string>(N);
	for (string& i : m) cin >> i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 'I') {
				Y = i, X = j;
			}
		}
	}

	check[Y][X] = true;
	dfs(Y, X);

	if (cnt) cout << cnt;
	else cout << "TT";

	return 0;
}