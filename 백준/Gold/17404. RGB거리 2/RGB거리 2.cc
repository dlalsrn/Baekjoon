#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> color;
vector <vector<int>> dp;
int N, mn = 1000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	color = vector<vector<int>>(N, vector<int>(3));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> color[i][j];

	for (int k = 0; k < 3; k++)
	{
		dp = vector<vector<int>>(N, vector<int>(3, 0));
		for (int i = 0; i < 3; i++)
		{
			if (k == i)
				dp[0][i] = color[0][i];
			else
				dp[0][i] = 1000001;
		}

		for (int i = 1; i < N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == k)
				continue;
			mn = min(mn, dp[N - 1][i]);
		}
	}

	cout << mn;

	return 0;
}