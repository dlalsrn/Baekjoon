#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, cnt;
vector <ll> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> K >> N;

	v.resize(K);

	for (int i = 0; i < K; i++)
		cin >> v[i];

	ll l = 1, r = (1 << 31) - 1, m;

	while (l < r)
	{
		m = (l + r + 1) / 2;

		cnt = 0;

		for (int i = 0; i < K; i++)
			cnt += v[i] / m;

		if (cnt >= N) l = m;
		else r = m - 1;
	}

	cout << r << '\n';

	return 0;
}