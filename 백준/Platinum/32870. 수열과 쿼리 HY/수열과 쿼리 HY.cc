#include <bits/stdc++.h>
using namespace std;

int N, Q, x, m, pre, mn, mx;
vector <int> v;
vector <pair<int, int>> ans(300001, { -1, -1 });

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	v = vector<int>(N);

	for (int& i : v) cin >> i;

	sort(v.begin(), v.end());

	for (int q = 0; q < Q; q++) {
		cin >> x;
		if (ans[x].first != -1) {
			cout << ans[x].first << ' ' << ans[x].second << '\n';
			continue;
		}
		m = 0;
		mn = x; mx = 0;
		pre = 0;

		while (m <= v.back()) {
			m += x;
			int index = lower_bound(v.begin(), v.end(), m) - v.begin();

			mn = min(mn, v[pre] % x);
			pre = index;
			if (index != 0) index--;
			mx = max(mx, v[index] % x);
		}

		cout << mn << ' ' << mx << '\n';
		ans[x] = { mn, mx };
	}

	return 0;
}