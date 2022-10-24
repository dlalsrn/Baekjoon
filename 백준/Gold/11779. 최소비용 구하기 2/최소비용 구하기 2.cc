// 최소비용 구하기 2
// 22.10.24
// 다익스트라 알고리즘
// 시작지점과 도착지점이 주어지면 시작지점에서 도착지점까지의 최단경로룰 구한 후 역추적
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int > pi;
stack <int> s;
vector <vector<pi>> node;
vector <vector<pi>> reverse_node;
vector <int> MIN_path;
priority_queue <pi, vector<pi>, greater<pi>> q;
int V, E, start, finish, u, v, w;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	node = vector<vector<pi>>(V + 1);
	reverse_node = vector<vector<pi>>(V + 1);
	MIN_path = vector<int>(V + 1, -1);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back(make_pair(v, w));
		reverse_node[v].push_back(make_pair(u, w));
	}

	cin >> start >> finish;

	MIN_path[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		pi t = q.top();
		q.pop();
		if (MIN_path[t.second] < t.first)
			continue;
		for (pi x : node[t.second])
		{
			int next_distance = x.second + t.first;
			if (MIN_path[x.first] == -1 || MIN_path[x.first] > next_distance)
			{
				MIN_path[x.first] = next_distance;
				q.push(make_pair(MIN_path[x.first], x.first));
			}
		}
	}

	s.push(finish);
	int total = MIN_path[finish];

	while (s.top() != start)
	{
		for (pi x : reverse_node[s.top()])
		{
			if (total - x.second == MIN_path[x.first])
			{
				s.push(x.first);
				total -= x.second;
				break;
			}
		}
		
	}

	cout << MIN_path[finish] << '\n';
	cout << s.size() << '\n';
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}