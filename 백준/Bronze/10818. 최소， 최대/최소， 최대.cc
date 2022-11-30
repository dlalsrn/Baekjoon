#include <iostream>
#include <algorithm>
#define inf 1000000
using namespace std;

int N, n, mx = -inf, mn = inf;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		mx = max(mx, n);
		mn = min(mn, n);
	}

	cout << mn << ' ' << mx;
	return 0;
}