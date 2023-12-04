#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (cin >> N)
	{
		if (N == 0)
			break;
		cout << N * (N + 1) / 2 << '\n';
	}

	return 0;
}