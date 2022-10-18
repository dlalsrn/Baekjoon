#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int > pi;
vector <vector<pi>> node;
vector <int> MIN_path;
priority_queue <pi, vector<pi>, greater<pi>> q;
int V, E, start, u, v, w;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E >> start;
	node = vector<vector<pi>>(V + 1);
	MIN_path = vector<int>(V + 1, 0);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0, start));

	while (!q.empty())
	{
		pi t = q.top(); // first : distance, second : node
		q.pop();
		if (MIN_path[t.second] < t.first)
			continue;
		for (pi x : node[t.second])
		{
			int next_distance = x.second + t.first;
			if ((MIN_path[x.first] == 0 && x.first != start) || MIN_path[x.first] > next_distance)
			{
				MIN_path[x.first] = next_distance;
				q.push(make_pair(MIN_path[x.first], x.first));
			}
		}
	}
	
	for (int i = 1; i <= V; i++)
	{
		if (i != start && !MIN_path[i])
			cout << "INF\n";
		else
			cout << MIN_path[i] << '\n';
	}

	return 0;
}