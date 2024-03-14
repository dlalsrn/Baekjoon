#include <bits/stdc++.h>
using namespace std;

int N, K, cnt = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0) cnt++;
		if (cnt == K)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;

	return 0;
}