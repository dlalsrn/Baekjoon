#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b;

	bool check_a = (a == 0 || a == 2 || a == 5);
	bool check_b = (b == 0 || b == 2 || b == 5);

	if (!check_a && check_b) cout << '<';
	else if (check_a && !check_b) cout << '>';
	else if (!check_a && !check_b) cout << '=';
	else
	{
		if (a == b) cout << '=';
		else if ((a == 0 && b == 2) || (a == 2 && b == 5) || (a == 5 && b == 0)) cout << '>';
		else cout << '<';
	}

	return 0;
}