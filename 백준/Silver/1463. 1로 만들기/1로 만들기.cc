#include <iostream>
#include <vector>
using namespace std;

int min(int n, int m)
{
	if (n >= m)
		return m;
	else
		return n;
}

int main(void)
{
	vector <int> dp;
	int N, num;
	cin >> N;
	for (int i = 0; i < N + 1; i++)
		dp.push_back(0);

	for (int i = N; i >= 1; i--)
	{
		if (i % 3 == 0)
		{
			if (dp[i / 3] == 0)
				dp[i / 3] = dp[i] + 1;
			else
				dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		}
		if (i % 2 == 0)
		{
			if (dp[i / 2] == 0)
				dp[i / 2] = dp[i] + 1;
			else
				dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		}
		if (dp[i - 1] == 0)
			dp[i - 1] = dp[i] + 1;
		else
			dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	cout << dp[1];
	return 0;
}