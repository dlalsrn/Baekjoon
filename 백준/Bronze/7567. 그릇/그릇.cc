#include <bits/stdc++.h>
using namespace std;

string x;
int ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	ans = 10;
	for (int i = 1; i < x.size(); i++)
	{
		if (x[i] == x[i - 1]) ans += 5;
		else ans += 10;
	}

	cout << ans;

	return 0;
}