#include <bits/stdc++.h>
using namespace std;

int a, b, sum = 0, mx = 0;

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;

		sum += b - a;
		mx = max(mx, sum);
	}

	cout << mx;

	return 0;
}