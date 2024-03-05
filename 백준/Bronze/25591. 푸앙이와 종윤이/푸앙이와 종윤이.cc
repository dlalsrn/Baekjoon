#include <bits/stdc++.h>
using namespace std;

int t1, t2, a, b, c, d, q, r;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> t1 >> t2;

	a = 100 - t1;
	b = 100 - t2;
	c = 100 - (a + b);
	d = a * b;
	q = d / 100;
	r = d % 100;
	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';

	c += q;
	d = r;

	cout << c << ' ' << d;

	return 0;
}