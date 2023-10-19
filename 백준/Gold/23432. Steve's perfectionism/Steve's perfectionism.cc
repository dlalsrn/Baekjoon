#include <iostream>
using namespace std;
using ll = long long;

ll N, x, t = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;

		if (x <= t)
			t = (t / x + 1) * x;
		else
			t = x;

		cout << t << ' ';
	}

	return 0;
}