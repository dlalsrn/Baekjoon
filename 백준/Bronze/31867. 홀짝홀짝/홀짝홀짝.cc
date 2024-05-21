#include <bits/stdc++.h>
using namespace std;

string x;
int N, odd = 0, even = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if ((x[i] - 48) % 2) odd++;
		else even++;
	}

	if (odd > even) cout << 1;
	else if (odd < even) cout << 0;
	else cout << -1;

	return 0;
}