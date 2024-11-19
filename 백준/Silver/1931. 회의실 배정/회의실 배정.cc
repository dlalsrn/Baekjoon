#include <bits/stdc++.h>
using namespace std;

int N, a, b, cnt = 0, finish = -1;
vector <pair<int, int>> v;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.emplace_back(b, a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (finish <= v[i].second) {
			finish = v[i].first;
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}