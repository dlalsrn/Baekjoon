#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <vector<pair<int, int>>> node;
vector <vector<pair<int, int>>> reverse_node;
vector <int> value;
vector <int> degree;
vector <bool> visit;
queue <int> order;
queue <int> trace;
int N, M, u, v, w, n, t, total, start, finish, cnt = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	node = vector<vector<pair<int, int>>>(N + 1);
	reverse_node = vector<vector<pair<int, int>>>(N + 1);
	degree = vector<int>(N + 1, 0);
	visit = vector<bool>(N + 1, false);
	value = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		reverse_node[v].push_back(make_pair(u, w));
		degree[v]++;
	}

	cin >> start >> finish;
	order.push(start);

	while (!order.empty())
	{
		t = order.front();
		order.pop();
		for (int i = 0; i< node[t].size(); i++)
		{
			n = node[t][i].first;
			degree[n]--;
			if (value[n] < value[t] + node[t][i].second)
				value[n] = value[t] + node[t][i].second;
			if (!degree[n])
				order.push(n);
		}
	}
	cout << value[finish] << '\n';

	trace.push(finish);
	while (!trace.empty())
	{
		t = trace.front();
		total = value[t];
		trace.pop();
		for (int i = 0; i < reverse_node[t].size(); i++)
		{
			n = reverse_node[t][i].first;
			if (total - reverse_node[t][i].second == value[n])
			{
				cnt++;
				if (!visit[n])
				{
					trace.push(n);
					visit[n] = true;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}