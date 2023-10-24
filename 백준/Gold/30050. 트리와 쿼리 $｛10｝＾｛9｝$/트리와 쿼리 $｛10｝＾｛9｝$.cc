#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map <ll, ll> m;
ll Q, ch, a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> ch >> a >> b;

		if (ch == 1)
			m[b] = a;
		else
		{
			ll ans = 0;
			while (a != b)
			{
				if (!m[a])
					m[a] = a / 2;
				if (!m[b])
					m[b] = b / 2;

				if (m[a] > m[b])
				{
					ans += a;
					a = m[a];
				}
				else
				{
					ans += b;
					b = m[b];
				}
			}
			
			cout << ans + a << '\n';
		}
	}

	return 0;
}