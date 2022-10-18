#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b)
{
	ll t;
	if (a < b)
		swap(a, b);
	while (a % b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	ll sum, a;
	ll ary[100001] = { 0 };
	cin >> N;
	for (int i = 1; i <= N - 2; i++)
	{
		cin >> a;
		ary[i] = a;
	}

	for (ll i = 1; i <= N - 3; i++)
	{
		sum = (ary[i] * ary[i+1]) / GCD(ary[i], ary[i+1]);
		ary[i + 1] = sum;
	}
	cout << ary[N - 2] << '\n';
	return 0;
}