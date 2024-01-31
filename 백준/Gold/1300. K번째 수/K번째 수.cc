#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	ll l = 1; ll r = N * N;

	while (l < r)
	{
		ll m = (l + r) >> 1;
		ll cnt = 0;

		for (int i = 1; i <= N; i++)
			cnt += min(m / i, N);

		if (cnt < K) l = m + 1;
		else r = m;
	}

	cout << r << '\n';

	return 0;
}