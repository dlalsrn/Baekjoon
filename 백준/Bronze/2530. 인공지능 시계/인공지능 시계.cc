#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, m, s, x;
int sum = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> h >> m >> s >> x;

	sum += h * 3600;
	sum += m * 60;
	sum += s;
	sum += x;

	cout << sum / 3600 % 24 << ' ' << sum % 3600 / 60 << ' ' << sum % 60;

	return 0;
}