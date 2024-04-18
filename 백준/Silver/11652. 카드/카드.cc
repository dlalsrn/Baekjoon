#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, x, mx = 0, ans;
map <ll, ll> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		m[x]++;
		if (mx <= m[x])
		{
			if (mx < m[x])
			{
				ans = x;
				mx = m[x];
			}
			else
			{
				if (ans > x)
					ans = x;
			}
		}
	}
	
	cout << ans;

	return 0;
}