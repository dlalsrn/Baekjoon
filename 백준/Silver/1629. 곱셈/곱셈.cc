#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n, ll m)
{
	if (n == 1)
		return x % m;
	if (n % 2 == 0)
	{
		ll y = power(x, n / 2, m);
		return y * y % m;
	}
	else
	{
		ll y = power(x, (n - 1) / 2, m);
		ll temp = y * y % m;
		return temp * x % m;
	}
}

int main(void)
{
	ll A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C);
	return 0;
}