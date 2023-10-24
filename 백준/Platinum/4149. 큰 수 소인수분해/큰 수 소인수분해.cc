#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

long long N;
long long sosu[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
vector <long long> v;

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
		t = (n - 1) / 2;

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

void pollard_ro(ll n)
{
	if (n == 1)
		return;
	if (n % 2 == 0)
	{
		v.push_back(2);
		pollard_ro(n / 2);
		return;
	}

	if (miller_rabin(n))
	{
		v.push_back(n);
		return;
	}

	ll a, b, c, g = n;
	auto f = [&](ll x)
	{
		return (mod_pow(x, 2, n) + c) % n;
	};

	do
	{
		if (g == n)
		{
			a = b = rand() % (n - 2) + 2;
			c = rand() % 20 + 1;
		}
		a = f(a);
		b = f(f(b));
		g = gcd(abs(a - b), n);
	} while (g == 1);

	pollard_ro(g);
	pollard_ro(n / g);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	pollard_ro(N);
	sort(v.begin(), v.end());
	
	for (long long x : v)
		cout << x << ' ';

	return 0;
}