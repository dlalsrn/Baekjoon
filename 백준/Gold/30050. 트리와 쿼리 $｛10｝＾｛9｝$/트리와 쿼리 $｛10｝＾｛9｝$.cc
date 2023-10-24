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
				if (m.find(a) == m.end() && m.find(b) == m.end())
				{
					if (a / 2 > b / 2)
					{
						ans += a;
						a /= 2;
					}
					else
					{
						ans += b;
						b /= 2;
					}
				}
				else if (m.find(b) == m.end())
				{
					if (m[a] > b / 2)
					{
						ans += a;
						a = m[a];
					}
					else
					{
						ans += b;
						b /= 2;
					}
				}
				else if (m.find(a) == m.end())
				{
					if (a / 2 > m[b])
					{
						ans += a;
						a /= 2;
					}
					else
					{
						ans += b;
						b = m[b];
					}
				}
				else
				{
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
			}
			
			cout << ans + a << '\n';
		}
	}

	return 0;
}