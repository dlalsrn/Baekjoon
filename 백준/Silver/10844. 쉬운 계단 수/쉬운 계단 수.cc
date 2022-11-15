#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000
using namespace std;

vector<vector<int>> dp;
int N, sum = 0;

int main(void)
{
	cin >> N;
	
	dp = vector<vector<int>>(10);

	for (int i = 0; i < 10; i++)
	{
		dp[i] = vector<int>(N, 0);
		dp[i][0] = 1;
	}

	
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j - 1 >= 0)
				dp[j - 1][i + 1] = (dp[j - 1][i + 1] + dp[j][i]) % MOD;
			if (j + 1 < 10)
				dp[j + 1][i + 1] = (dp[j + 1][i + 1] + dp[j][i]) % MOD;
		}
	}

	for (int i = 0; i < 9; i++)
		sum = (sum + dp[i][N - 1]) % MOD;

	cout << sum;

	return 0;
}
