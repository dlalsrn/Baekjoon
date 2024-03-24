#include <bits/stdc++.h>
using namespace std;

long long N = 0, S, cnt = 1;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> S;

	while (true)
	{
		N++;
		S -= cnt++;

		if (cnt > S)
		{
			cout << N;
			break;
		}
	}

	return 0;
}