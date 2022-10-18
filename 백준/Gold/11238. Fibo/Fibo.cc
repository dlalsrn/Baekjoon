// Fibo
// GCD(fibo(n), fibo(m)) = fibo(GCD(n, m))
#include <iostream>
#include <map>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll fibo(ll n, map <ll, ll>* m)
{
	if (n == 0 || n == 1)
		return (*m)[n];
	else if ((*m)[n])
		return (*m)[n];
	else
	{
		if (n % 2 == 0)
		{
			ll t = fibo(n / 2, m) % MOD;
			ll s = fibo(n / 2 - 1, m) % MOD;
			(*m)[n / 2] = t;
			(*m)[n / 2 - 1] = s;
			(*m)[n] = t * (2 * s + t) % MOD;
			return t * (2 * s + t) % MOD;
		}
		else
		{
			ll t = fibo(n / 2, m) % MOD;
			ll s = fibo(n / 2 + 1, m) % MOD;
			(*m)[n / 2] = t;
			(*m)[n / 2 + 1] = s;
			(*m)[n] = (t * t + s * s) % MOD;
			return (t * t + s * s) % MOD;
		}
	}
}

int main(void)
{
	map <ll, ll> m;
	m[0] = 0;
	m[1] = 1;
	ll a, b, T;
	cin >> T;

	for (ll i = 0; i < T; i++)
	{
		cin >> a >> b;
		while (b % a != 0)
		{
			ll temp = b % a;
			b = a;
			a = temp;
		}
		cout << fibo(a, &m) % MOD << '\n';
	}
	return 0;
}