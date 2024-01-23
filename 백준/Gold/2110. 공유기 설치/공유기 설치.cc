#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, C;
vector <ll> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> C;

	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());


	ll l = 1, r = v[N - 1] - v[0];
	
	while (l < r)
	{
		ll m = (l + r + 1) >> 1;

		ll cnt = 1;
		ll prev = v[0];

		for (int i = 1; i < N; i++)
		{
			if (v[i] - prev >= m)
			{
				cnt++;
				prev = v[i];
			}
		}

		if (cnt >= C) l = m;
		else r = m - 1;
	}

	cout << r << '\n';

	return 0;
}