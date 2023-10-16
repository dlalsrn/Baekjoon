#include <iostream>
using namespace std;
using ll = __int128;

long long a, b;
ll N;
ll sosu[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

ll mod_pow(ll a, ll b, ll m)
{
	ll r = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
			r = (r * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return r;
}

bool miller_rabin(ll n)
{
	ll k = 0, q;
	ll t = n - 1;
	while (!(t & 1))
	{
		t >>= 1;
		k++;
	}
	q = t;

	for (int i = 0; i < 12; i++)
	{
		bool isprime = false;
		t = n - 1;

		if (sosu[i] >= n - 1)
			break;
		if (n % sosu[i] == 0)
			return false;

		ll s = mod_pow(sosu[i], q, n);
		if (s == 1)
		{
			isprime = true;
			continue;
		}

		while (1)
		{
			ll ans = mod_pow(sosu[i], t, n);
			if (ans == n - 1)
			{
				isprime = true;
				break;
			}
			if (t % 2)
				break;
			t /= 2;
		}
		if (isprime)
			continue;

		return false;
	}

	return true;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b;

	for (long long K = a; K <= b; K++)
	{
		if (K % 2 == 0)
			continue;
		if (K < 15)
			cout << K << ' ';
		else if (miller_rabin((ll)K))
			cout << K << ' ';
	}

	return 0;
}