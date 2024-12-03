#include <bits/stdc++.h>
using namespace std;

int N;
vector <vector<int>> v;
vector <vector<bool>> path;
vector <bool> check;
queue <int> q;

void floyd() {
	for (int i = 0; i < N; i++) {
		q.push(i);
		check = vector<bool>(N, false);

		while (!q.empty()) {
			int n = q.front();
			q.pop();

			for (int j = 0; j < N; j++) {
				if (v[n][j] && !check[j]) {
					q.push(j);
					path[i][j] = true;
					check[j] = true;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v = vector<vector<int>>(N , vector<int>(N));
	path = vector<vector<bool>>(N , vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	floyd();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << path[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}