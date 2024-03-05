#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b;

	cout << (a >= b ? a + b : b - a);

	return 0;
}