#include <bits/stdc++.h>
using namespace std;

int N, sum;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> N;

		if (N == 0) break;

		sum = 0;

		for (int i = 1; i <= N; i++)
			sum += i * i;

		cout << sum << '\n';
	}

	return 0;
}