#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
typedef long long ll;

ll N, K, ans = 0;

int main(void)
{
	cin >> N >> K;

	if (K == 1)
	{
		cout << 0;
		return 0;
	}

	for (ll i = 1; i <= N; i++)
	{
		ll G = 1;
		int t = log10(i) + 1;
		while (t--)	G *= 10;
		ans = ans * G + i;
		if (ans >= K)
			ans %= K;
	}

	cout << ans % K;

	return 0;
}