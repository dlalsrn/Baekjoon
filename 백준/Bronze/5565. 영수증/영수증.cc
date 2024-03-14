#include <bits/stdc++.h>
using namespace std;

int total, x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> total;

	for (int i = 0; i < 9; i++)
	{
		cin >> x;
		total -= x;
	}

	cout << total;

	return 0;
}