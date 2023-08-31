#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int N, M, u, v, c;
vector <vector<pi>> node;
vector <int> MIN_path;
vector <pi> ans;
vector <bool> visit;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N >> M;
	
	node = vector<vector<pi>>(N + 1);
	MIN_path = vector<int>(N + 1, 1e6);
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> c;
		node[u].push_back(make_pair(v, c));
		node[v].push_back(make_pair(u, c));
	}

	MIN_path[1] = 0;
	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		int n = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (MIN_path[n] < cost)
			continue;

		for (pi next : node[n])
		{
			if (MIN_path[next.first] > next.second + cost)
			{
				MIN_path[next.first] = next.second + cost;
				pq.push(make_pair(MIN_path[next.first], next.first));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (pi next : node[i])
		{
			if (MIN_path[i] + next.second == MIN_path[next.first] && !visit[next.first])
			{
				u = i;
				v = next.first;
				visit[v] = true;
				if (u > v)
					swap(u, v);
				ans.push_back(make_pair(u, v));
			}
		}
	}

	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';

	return 0;
}