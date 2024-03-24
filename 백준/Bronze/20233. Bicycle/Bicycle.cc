#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b >> c >> d >> t;

	cout << (t <= 30 ? a : a + 21 * ((t - 30) * b)) << ' ';
	cout << (t <= 45 ? c : c + 21 * ((t - 45) * d)) << ' ';

	return 0;
}