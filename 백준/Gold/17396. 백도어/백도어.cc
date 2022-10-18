#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
vector <ll> dist;
vector <vector<pi>> node;
vector <ll> check;
priority_queue <pi, vector<pi>, greater<pi>> q;
ll N, M, c, u, v, w;

void dijk(void)
{
	while (!q.empty())
	{
		ll next = q.top().second;
		ll d = q.top().first;
		q.pop();
		if (dist[next] < d)
			continue;
		for (pi x : node[next])
		{
			if (check[x.first] && x.first != N - 1)
				continue;
			if (dist[x.first] == -1 || dist[x.first] > d + x.second)
			{
				dist[x.first] = d + x.second;
				q.push(make_pair(dist[x.first], x.first));
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	node = vector<vector<pi>>(N);
	dist = vector<ll>(N, -1);
	check = vector<ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> check[i];

	for (ll i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		node[v].push_back(make_pair(u, w));
	}

	q.push(make_pair(0, 0));
	dist[0] = 0;
	dijk();

	cout << (dist[N - 1] == -1 ? -1 : dist[N - 1]);

	return 0;
}