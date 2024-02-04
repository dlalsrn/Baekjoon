#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll N, K;
vector <vector<ll>> dp;
vector <pl> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	dp = vector<vector<ll>>(N + 1, vector<ll>(K + 1, 0));
	v.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> v[i].first >> v[i].second;

	for (ll i = 1; i <= N; i++)
	{
		for (ll k = 0; k <= K; k++)
		{
			if (v[i].first > k) dp[i][k] = dp[i - 1][k];
			else dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - v[i].first] + v[i].second);
		}
	}
	
	cout << dp[N][K];

	return 0;
}