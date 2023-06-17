#include <iostream>
#define MOD 1000000007
using namespace std;

using ll = long long;
ll N, s = 0;

ll pow(ll n)
{
	if (n == 1 || n == 0)
		return 2;
	else
	{
		ll x = pow(n/2) % MOD;
		if (n % 2)
			return x * x * 2 % MOD;
		else
			return x * x % MOD;
	}
}

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		s = (s + pow(i)) % MOD;

	cout << (2 * s - 1) % MOD;

	return 0;
}