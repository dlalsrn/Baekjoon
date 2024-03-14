#include <bits/stdc++.h>
using namespace std;

int A, B;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> A >> B;

		if (A == 0 && B == 0) break;

		cout << A * 2 - B << '\n';
	}

	return 0;
}