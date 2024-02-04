#include <bits/stdc++.h>
using namespace std;

string x1, x2;
vector <vector<int>> dp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x1 >> x2;

	dp = vector<vector<int>>(x2.size() + 1, vector<int>(x1.size() + 1, 0));

	for (int i = 1; i < x2.size() + 1; i++)
	{
		for (int j = 1; j < x1.size() + 1; j++)
		{
			if (x1[j - 1] == x2[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[x2.size()][x1.size()];

	return 0;
}