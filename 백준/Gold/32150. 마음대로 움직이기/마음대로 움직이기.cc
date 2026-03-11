#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, Q, T, P;
ll L, R;
vector<ll> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		ll x;
		cin >> x;
		v.emplace_back(x);
	}

	sort(v.begin(), v.end());

	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> T >> P;

		if (v.empty())
		{
			cout << T + 1 << '\n';
			continue;
		}

		auto it = lower_bound(v.begin(), v.end(), P);

		if (it == v.begin())
		{
			L = P - T;
			R = min(P + T, v[0] - 1);
		}
		else if (it == v.end())
		{
			L = max(P - T, v.back() + 1);
			R = P + T;
		}
		else
		{
			L = max(P - T, *(it - 1) + 1);
			R = min(P + T, *it - 1);
		}

		ll ans = 0;

		if (L <= R)
		{
			ll first = L;

			if(((first - P) & 1) != (T & 1)) first++;

			if (first <= R) ans = (R - first) / 2 + 1;
		}

		cout << ans << '\n';
	}

	return 0;
}