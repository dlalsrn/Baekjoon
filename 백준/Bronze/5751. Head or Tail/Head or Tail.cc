#include <bits/stdc++.h>
using namespace std;

int N, zero, one, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> N;

		if (N == 0) break;

		zero = one = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> x;
			if (x == 0) zero++;
			else one++;
		}

		cout << "Mary won " << zero << " times and John won " << one << " times\n";
	}

	return 0;
}