#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> dp;
int N;

int main(void)
{
	cin >> N;
	dp = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
		dp[i] = i;

	for (int i = 1; i <= N; i++)
	{
		if (i + 1 <= N)
			dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
		if (i * 2 <= N)
			dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
		if (i * 3 <= N)
			dp[i * 3] = min(dp[i] + 1, dp[i * 3]);
	}

	cout << dp[N] - 1 << '\n';
	int n = N;
	while (n)
	{
		cout << n << ' ';
		if (dp[n - 1] == dp[n] - 1)
			n -= 1;
		else if (n % 2 == 0 && dp[n / 2] == dp[n] - 1)
			n /= 2;
		else if (n % 3 == 0 && dp[n / 3] == dp[n] - 1)
			n /= 3;
	}

	return 0;
}