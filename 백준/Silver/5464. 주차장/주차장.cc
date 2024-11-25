#include <bits/stdc++.h>
using namespace std;

int N, M, x, ans = 0, cnt = 0;
vector <int> cost, weight, check;
queue <int> q;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	cost = vector<int>(N);
	weight = vector<int>(M);
	check = vector<int>(N, -1);

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 0; i < M; i++)
		cin >> weight[i];

	for (int i = 0; i < M * 2; i++) {
		cin >> x;

		if (x > 0) { // 주차
			if (cnt == N) { // 모두 주차
				q.push(x);
				continue;
			}

			for (int i = 0; i < N; i++) {
				if (check[i] == -1) {
					check[i] = x;
					ans += cost[i] * weight[x - 1];
					cnt++;
					break;
				}
			}
		}
		else { // 출차
			x *= -1;
			for (int i = 0; i < N; i++) {
				if (check[i] == x) {
					if (!q.empty()) {
						check[i] = q.front();
						ans += cost[i] * weight[q.front() - 1];
						q.pop();
					}
					else {
						check[i] = -1;
						cnt--;
					}
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}