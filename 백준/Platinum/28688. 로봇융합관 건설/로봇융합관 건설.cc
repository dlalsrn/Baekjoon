#include <bits/stdc++.h>
using namespace std;

long long T, a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> a >> b;
		if (a <= 2 || b <= 2)
			cout << "First\n";
		else if (a % 2)
		{
			if (b % 2)
				cout << "First\n";
			else
				cout << "Second\n";
		}
		else
			cout << "Second\n";
	}

	return 0;
}