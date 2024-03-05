#include <bits/stdc++.h>
using namespace std;

string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0;;)
	{
		cout << x[i];
		if (i == x.size() - 1) break;
		i += x[i] - 'A' + 1;
	}

	return 0;
}