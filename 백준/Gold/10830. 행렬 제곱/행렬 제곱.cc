#include <bits/stdc++.h>
#define MOD 1000
using namespace std;
using ll = long long;

ll N, B;
vector <vector<ll>> v, t, ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> B;

	v = t = ans = vector<vector<ll>>(N, vector<ll>(N, 0));

	for (ll i = 0; i < N; i++)
		ans[i][i] = 1;

	for (ll i = 0; i < N; i++)
		for (ll j = 0; j < N; j++)
			cin >> v[i][j];

	while (B)
	{
		if (B & 1)
		{
			for (ll i = 0; i < N; i++)
			{
				for (ll k = 0; k < N; k++)
				{
					ll x = 0;
					for (ll j = 0; j < N; j++)
						x = (x + ans[i][j] * v[j][k]) % MOD;
					t[i][k] = x;
				}
			}

			ans = t;
		}

		for (ll i = 0; i < N; i++)
		{
			for (ll k = 0; k < N; k++)
			{
				ll x = 0;
				for (ll j = 0; j < N; j++)
					x = (x + v[i][j] * v[j][k]) % MOD;
				t[i][k] = x;
			}
		}
		v = t;
		B >>= 1;
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	
	return 0;
}