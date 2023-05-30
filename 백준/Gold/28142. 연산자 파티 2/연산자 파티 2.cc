#include <iostream>
#define MOD 1000000007
using namespace std;
using ll = long long;

ll N, X;

ll pw(ll n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
	{
		ll x = pw(n / 2) % MOD;
		return (n % 2 ? (x * x * 2) % MOD : (x * x) % MOD);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	ll i = N / 255 * 255;
	X = i;
	if (i % 1023 == 0)
		X = ((i % MOD) * (pw(i) % MOD)) % MOD;

	for (ll j = i + 1; j <= N; j++)
	{
		X = abs(X - j);
		if (j % 3 == 0)
			X = ((X % MOD) * (j % MOD)) % MOD;
		if (j % 15 == 0)
			X = (X & j);
		if (j % 63 == 0)
			X = (X ^ j);
		if (j % 255 == 0)
			X = (X | j);
		if (j % 1023 == 0)
			X = ((X % MOD) * (pw(j) % MOD)) % MOD;
	}

	cout << X;

	return 0;
}