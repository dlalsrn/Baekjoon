#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, M, a, b, ans, mn, sum;
vector <vector<int>> v, path;
queue <pi> q;

void bfs() {
	for (int i = 1; i <= N; i++) {
		path[i][i] = 0;
		q.push(make_pair(i, 0));
	
		while (!q.empty()) {
			int n = q.front().first;
			int cnt = q.front().second;
			q.pop();

			for (int x : v[n]) {
				if (path[i][x] == -1) {
					path[i][x] = cnt + 1;
					q.push(make_pair(x, cnt + 1));
				}
			}
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;
	v = vector<vector<int>>(N + 1);
	path = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	mn = N * N;

	bfs();

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += path[i][j];
		}
		
		if (mn > sum) {
			mn = sum;
			ans = i;
		}
	}
	
	cout << ans;

	return 0;
}