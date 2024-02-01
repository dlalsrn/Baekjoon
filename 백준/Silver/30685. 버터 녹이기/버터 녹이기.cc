#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll N, cnt = 0;
vector <pl> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	cnt = 0;
	for (int i = 0; i < N - 1; i++)
	{
		ll x = v[i].first + v[i].second / 2;
		ll y = v[i + 1].first - v[i + 1].second / 2;

		if (x < y) cnt++;
	}

	if (cnt == N - 1)
	{
		cout << "forever";
		return 0;
	}

	ll l = 0, r = 1e9 - 1;

	while (l < r)
	{
		ll m = (l + r + 1) >> 1;
		cnt = 0;

		for (int i = 0; i < N - 1; i++)
		{
			ll x = v[i].first + min(v[i].second / 2, m);
			ll y = v[i + 1].first - min(v[i + 1].second / 2, m);

			if (x < y) cnt++;
		}

		if (cnt == N - 1) l = m;
		else r = m - 1;
	}

	cout << r;

	return 0;
}