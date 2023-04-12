#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll N, sum = 0, ans = 0, fac = 1;

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		sum = (sum + i * 2) % MOD;
		ans = (ans + sum * i) % MOD;
		fac = (fac * i) % MOD;
	}

	cout << ans << ' ' << fac * fac % MOD;
}