// 피보나치 수 6
#include <iostream>
#include <map>
#define MOD 1000000000
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
	ll a, b;
	cin >> a >> b;
	cout << ((fibo(b + 2, &m) - 1) - (fibo(a + 1, &m) - 1)+MOD) % MOD;
	return 0;
}