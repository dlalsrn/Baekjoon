#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll N, M, R, u, v, cnt = 0;
long long ans = 0;
queue <ll> q;
vector <vector<ll>> node;
vector <ll> order, depth;
vector <bool> check;
vector <pi> edge;

void bfs()
{
	while (!q.empty())
	{
		ll n = q.front();
		q.pop();
		ll c = order[n];
		ll d = depth[n];

		for (ll x : node[n])
		{
			if (!check[x])
			{
				check[x] = true;
				order[x] = ++cnt;
				depth[x] = d + 1;
				q.push(x);
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> R;

	order = vector<ll>(N + 1, 0);
	depth = vector<ll>(N + 1, -1);
	check = vector<bool>(N + 1, false);
	node = vector<vector<ll>>(N + 1);

	for (ll i = 0; i < M; i++)
	{
		cin >> u >> v;
		edge.emplace_back(u, v);
	}

	sort(edge.begin(), edge.end());

	for (ll i = 0; i < M; i++)
	{
		u = edge[i].first;
		v = edge[i].second;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	q.push(R);
	check[R] = true;
	order[R] = ++cnt;
	depth[R] = 0;

	bfs();

	for (ll i = 1; i <= N; i++)
		ans += order[i] * depth[i];

	cout << ans;

	return 0;
}