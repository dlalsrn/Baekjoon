#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;
vector <ll> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	ll l = 0, r = 1e9;

	while (l < r)
	{
		ll m = (l + r + 1) >> 1;

		ll cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += max((ll)0, v[i] - m);

		if (M <= cnt) l = m;
		else r = m - 1;
	}

	cout << r << '\n';

	return 0;
}