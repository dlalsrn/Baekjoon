#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map <ll, ll> m;
ll mn, mx, cnt;

int main(void)
{
	cin >> mn >> mx;

	cnt = mx - mn + 1;

	for (ll i = 2; i <= 1000000; i++)
	{
		ll diff = (mn % (i * i) ? i * i - (mn % (i * i)) : 0);
		for (ll j = mn + diff; j <= mx; j += i * i)
			if (!m[j]++)
				cnt--;
	}

	cout << cnt;

	return 0;
}