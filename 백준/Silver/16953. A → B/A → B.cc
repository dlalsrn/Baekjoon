#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, cnt = 1;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> A >> B;

	while (B)
	{
		if (B == A)
		{
			cout << cnt;
			return 0;
		}
		if (B % 10 == 1)
		{
			B /= 10;
			cnt++;
		}
		else if (B % 2 == 0)
		{
			B /= 2;
			cnt++;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << -1;

	return 0;
}