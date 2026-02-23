#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
using pi = pair<int, int>;

int N, M, S;
int answer = 0;
vector<vector<pi>> node;
vector<bool> check;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> S;

	node = vector<vector<pi>>(N + 1);
	check = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node[u].emplace_back(v, w);
		node[v].emplace_back(u, w);
	}

	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
	}

	pq.push(make_pair(0, S));

	while (!pq.empty())
	{
		auto [cost, next] = pq.top();
		pq.pop();

		if (check[next]) continue;

		check[next] = true;
		answer += cost;

		for (pi& edge : node[next])
		{
			if (!check[edge.first])
			{
				pq.push(make_pair(edge.second, edge.first));
			}
		}
	}

	cout << answer;

	return 0;
}