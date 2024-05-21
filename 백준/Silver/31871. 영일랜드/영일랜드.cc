#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int N, M, u, v, t, cnt = 0, ans;
vector <vector<int>> W;
vector <vector<int>> dp;

int dfs(int n, int visit)
{
	if (visit == (1 << (N + 1)) - 1)
	{
		if (W[n][0] == 0) return -INF;
		else return W[n][0];
	}

	if (dp[n][visit] != -1) return dp[n][visit];

	dp[n][visit] = -INF;

	for (int i = 0; i < N + 1; i++)
	{
		if (!W[n][i] || visit & (1 << i)) continue;
		dp[n][visit] = max(dp[n][visit], W[n][i] + dfs(i, visit | 1 << i));
	}

	return dp[n][visit];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	W = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	dp = vector<vector<int>>(N + 1, vector<int>(1 << (N + 1), -1));

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> t;
		if (u == v) continue;
		W[u][v] = max(W[u][v], t);
	}

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	ans = dfs(0, 1);

	cout << (ans < 0 ? -1 : ans);

	return 0;
}
