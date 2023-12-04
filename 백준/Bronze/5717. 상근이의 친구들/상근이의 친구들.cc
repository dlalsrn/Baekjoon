#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, F;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	while (true)
	{
		cin >> M >> F;
		if (M == 0 && F == 0)
			break;
		cout << M + F << '\n';
	}

	return 0;
}