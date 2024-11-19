#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector <pair<int, int>> v;
vector <int> ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	ans = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				cnt++;
			}
		}
		ans[i] = cnt + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}