// gcd(n, k) = 1
// 23.10.24
// 폴라드로, 밀러라빈
// N의 phi(N) 값을 구하는 문제
// 각 소인수를 x1, x2, x3, ...라 했을 때 phi(N)은 아래와 같음
// phi(N) = N * ((x1 - 1) / x1) * ((x2 - 1) / x2) * ((x3 - 1) / x3)...
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
using ll = __int128;
using lli = long long;

lli N, ans = 1;
lli sosu[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
vector <lli> v;

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

	lli t = v[0], cnt = 0;

	for (lli x : v)
	{
		if (x == t)
			cnt++;
		else
		{
			ans *= cnt + 1;
			t = x;
			cnt = 1;
		}
	}

	cout << ans * (cnt + 1);

	return 0;
}