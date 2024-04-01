
#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> dp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	dp.resize(N + 1, 100000);
	dp[0] = 0;
	if (N >= 1) dp[1] = 1;
	if (N >= 2) dp[2] = 1;
	if (N >= 5) dp[5] = 1;
	if (N >= 7) dp[7] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (i - 1 > 0) dp[i] = min(dp[i], dp[i - 1] + 1);
		if (i - 2 > 0) dp[i] = min(dp[i], dp[i - 2] + 1);
		if (i - 5 > 0) dp[i] = min(dp[i], dp[i - 5] + 1);
		if (i - 7 > 0) dp[i] = min(dp[i], dp[i - 7] + 1);
	}

	cout << dp[N];

	return 0;
}