#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K;
ll dx[4] = { 1, 0,-1, 0 };
ll dy[4] = { 0, 1, 0, -1 };
vector <vector<ll>> m;
vector <vector<bool>> check;

void dfs(ll y, ll x)
{
	if (M == 0)
		return;

	check[y][x] = true;
	M--;

	for (ll k = 0; k < 4; k++)
	{
		ll xx = x + dx[k];
		ll yy = y + dy[k];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N || check[yy][xx] || m[yy][xx])
			continue;

		dfs(yy, xx);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> K;

	M *= K;
	m = vector<vector<ll>>(N, vector<ll>(N));
	check = vector<vector<bool>>(N, vector<bool>(N, false));

	for (ll i = 0; i < N; i++)
		for (ll j = 0; j < N; j++)
			cin >> m[i][j];

	bool TF = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!m[i][j])
				TF = false;

	if (M == 0 || TF)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (!check[i][j] && M == 0 && m[i][j] == 0)
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
			if (!check[i][j] && m[i][j] == 0)
				dfs(i, j);
			M = M / K * K;
		}
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
		{
			if (m[i][j] == 0 && !check[i][j])
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}

	cout << "POSSIBLE\n";
	cout << M / K;

	return 0;
}