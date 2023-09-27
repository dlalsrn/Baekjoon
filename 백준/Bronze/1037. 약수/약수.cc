#include <iostream>
#include <algorithm>
using namespace std;

int N, mx = 1, mn = 1e10, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
	}

	cout << mx * mn;

	return 0;
}