#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll T, N, M, u, v, c;
bool cycle = false;
vector <vector<pair<ll, ll>>> node;
vector <ll> dist;
vector <ll> ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	node = vector<vector<pair<ll, ll>>>(N + 1);
	dist = vector<ll>(N + 1, 1e18);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> c;
		node[u].push_back(make_pair(v, c));
	}

	dist[1] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[j] != 1e18)
			{
				for (pair<ll, ll> x : node[j])
				{
					int next = x.first;
					int cost = x.second;
					if (dist[next] > cost + dist[j])
					{
						dist[next] = cost + dist[j];
						if (i == N - 1)
							cycle = true;
					}
				}
			}
		}
	}

	if (cycle)
	{
		cout << -1;
		return 0;
	}

	for (int i = 2; i <= N; i++)
		cout << (dist[i] == 1e18 ? -1 : dist[i]) << '\n';

	return 0;
}
