#include <iostream>
#define MOD 1000000007
using namespace std;

using ll = long long;
ll N, s = 3, x = 4;

int main(void)
{
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		s = (s + x * 2) % MOD;
		x = (x << 1) % MOD;
	}

	cout << s;

	return 0;
}