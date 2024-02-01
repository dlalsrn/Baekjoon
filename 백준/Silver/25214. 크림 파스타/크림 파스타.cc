#include <bits/stdc++.h>
using namespace std;

int N, mx = 0, l = 1e9, r = 0, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (r < x) r = x;
		if (l > x) l = r = x;
		mx = max(mx, r - l);

		cout << mx << ' ';
	}

	return 0;
}