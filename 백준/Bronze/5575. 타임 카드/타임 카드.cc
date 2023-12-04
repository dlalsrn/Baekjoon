#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, c, d, e, f;
int s1, s2;
int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c >> d >> e >> f;

		s1 = a * 3600 + b * 60 + c;
		s2 = d * 3600 + e * 60 + f;

		s2 -= s1;
		cout << s2 / 3600 % 24 << ' ' << s2 % 3600 / 60 << ' ' << s2 % 60 << '\n';
	}

	return 0;
}