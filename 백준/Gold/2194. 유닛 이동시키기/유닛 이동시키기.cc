#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pi = pair<int, int>;
using ti3 = tuple<int, int, int>; // y x cnt

int N, M, A, B, K, r, c, ans = -1;
vector<vector<bool>> check;
vector<vector<bool>> wall;
pi start, finish;
queue <ti3> q;

void bfs() {
	int yyy, xxx;
	while (!q.empty()) {
		auto [yy, xx, cnt] = q.front();
		q.pop();

		if (yy == finish.y && xx == finish.x) {
			ans = cnt;
			return;
		}

		yyy = yy; xxx = xx + 1; // 오른쪽 이동
		if (xxx + B < M && !check[yyy][xxx]) {
			bool TF = true;
			for (int i = yyy; i <= yyy + A; i++) {
				if (wall[i][xxx + B]) { // 장애물이 있다면
					TF = false;
					break;
				}
			}
			if (TF) {
				check[yyy][xxx] = true;
				q.push(make_tuple(yyy, xxx, cnt + 1));
			}
		}

		yyy = yy; xxx = xx - 1; // 왼쪽 이동
		if (xxx >= 0 && !check[yyy][xxx]) {
			bool TF = true;
			for (int i = yyy; i <= yyy + A; i++) {
				if (wall[i][xxx]) { // 장애물이 있다면
					TF = false;
					break;
				}
			}
			if (TF) {
				check[yyy][xxx] = true;
				q.push(make_tuple(yyy, xxx, cnt + 1));
			}
		}

		yyy = yy - 1; xxx = xx; // 위쪽 이동
		if (yyy >= 0 && !check[yyy][xxx]) {
			bool TF = true;
			for (int i = xxx; i <= xxx + B; i++) {
				if (wall[yyy][i]) { // 장애물이 있다면
					TF = false;
					break;
				}
			}
			if (TF) {
				check[yyy][xxx] = true;
				q.push(make_tuple(yyy, xxx, cnt + 1));
			}
		}

		yyy = yy + 1; xxx = xx; // 아래쪽 이동
		if (yyy + A < N && !check[yyy][xxx]) {
			bool TF = true;
			for (int i = xxx; i <= xxx + B; i++) {
				if (wall[yyy + A][i]) { // 장애물이 있다면
					TF = false;
					break;
				}
			}
			if (TF) {
				check[yyy][xxx] = true;
				q.push(make_tuple(yyy, xxx, cnt + 1));
			}
		}
	}
}

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> A >> B >> K;

	check = vector<vector<bool>>(N, vector<bool>(M, false));
	wall = vector<vector<bool>>(N, vector<bool>(M, false));
	A--; B--;

	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		wall[--r][--c] = true;
	}

	cin >> start.y >> start.x >> finish.y >> finish.x;
	start.y--; start.x--;
	finish.y--; finish.x--;

	q.push(make_tuple(start.y, start.x, 0));
	check[start.y][start.x] = true;

	bfs();

	cout << ans;

	return 0;
}