#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N;
vector <vector<int>> W;
vector <vector<int>> dp;

int dfs(int n, int visit)
{
	if (visit == (1 << N) - 1)
	{
		if (W[n][0] == 0) return INF;
		else return W[n][0];
	}

	if (dp[n][visit] != -1) return dp[n][visit];

	dp[n][visit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (!W[n][i] || visit & (1 << i)) continue;
		dp[n][visit] = min(dp[n][visit], W[n][i] + dfs(i, visit | 1 << i));
	}

	return dp[n][visit];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	W = vector<vector<int>>(N + 1, vector<int>(N + 1));
	dp = vector<vector<int>>(N + 1, vector<int>(1 << N, -1));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	cout << dfs(0, 1);

	return 0;
}