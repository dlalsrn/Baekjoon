#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b >> c >> d;

	cout << (a * b > c * d ? 'M' : (a * b != c * d ? 'P' : 'E'));

	return 0;
}