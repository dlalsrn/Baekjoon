#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> v, dp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max({ v[1] + v[2], v[1] + v[3], v[2] + v[3] });

	for (int i = 4; i <= N; i++)
		dp[i] = max({ dp[i - 1], dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i] });

	cout << dp[N] << '\n';

	return 0;
}