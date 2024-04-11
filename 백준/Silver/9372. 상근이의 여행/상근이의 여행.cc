#include <bits/stdc++.h>
using namespace std;

int T, N, M, a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> a >> b;
		cout << N - 1 << '\n';
	}

	return 0;
}