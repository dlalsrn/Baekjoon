#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string x;
int a, w;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> x >> a >> w;
		if (x == "#")
			break;
		cout << x;
		cout << ((a > 17 || w >= 80) ? " Senior\n" : " Junior\n");
	}

	return 0;
}