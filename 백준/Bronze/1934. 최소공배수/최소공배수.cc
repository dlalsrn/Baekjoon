#include <bits/stdc++.h>
using namespace std;

int N, a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		int c = a;
		int d = b;

		while (c != d)
		{
			if (c < d) c += a;
			else d += b;
		}

		cout << c << '\n';
	}

	return 0;
}