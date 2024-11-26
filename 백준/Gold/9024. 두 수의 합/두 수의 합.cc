#include <bits/stdc++.h>
using namespace std;

int T, N, K, l, r;
vector <int> v;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N >> K;
		v = vector<int>(N);
		for (int& i : v) cin >> i;
		sort(v.begin(), v.end());

		int l = 0, r = v.size() - 1, mn = 1e9 + 1, cnt = 0, sum;
		while (l < r) {
			sum = v[l] + v[r];

			if (abs(K - sum) < mn) {
				cnt = 1;
				mn = abs(K - sum);
			}
			else if (abs(K - sum) == mn) {
				cnt++;
			}

			if (sum < K) {
				l++;
			}
			else if (sum > K) {
				r--;
			}
			else {
				l++;
				r--;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}