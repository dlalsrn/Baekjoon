#include <bits/stdc++.h>
using namespace std;

int N, ans;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector <string> m;
vector <vector<bool>> check;

void dfs(int y, int x, char c, bool rg) {
	for (int k = 0; k < 4; k++) {
		int yy = y + dy[k];
		int xx = x + dx[k];
		if (yy < 0 || yy >= N || xx < 0 || xx >= N || check[yy][xx])
			continue;
		if (rg) {
			if ((c == 'B' && m[yy][xx] != c) || ((c == 'R' || c == 'G') && m[yy][xx] == 'B')) {
				continue;
			}
		}
		else {
			if (m[yy][xx] != c) {
				continue;
			}
		}
		check[yy][xx] = true;
		dfs(yy, xx, c, rg);
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	m = vector<string>(N);

	for (string& i : m)
		cin >> i;

	check = vector<vector<bool>>(N, vector<bool>(N, false));
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				ans++;
				dfs(i, j, m[i][j], false);
			}
		}
	}
	cout << ans << ' ';
	
	check = vector<vector<bool>>(N, vector<bool>(N, false));
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				ans++;
				dfs(i, j, m[i][j], true);
			}
		}
	}
	cout << ans;

	return 0;
}