#include <bits/stdc++.h>
using namespace std;

int T, N, M, x, y;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;

		int lcm = M * N / gcd(M, N);
		int ans = -1;

		for (int i = x; i <= lcm; i += M) {
			int t = (i % N != 0 ? i % N : N);

			if (t == y) {
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}