#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector <vector<pi>> node;
vector <vector<pi>> reverse_node;
vector <vector<bool>> check;
vector <bool> check_node;
vector <int> MIN_path;
priority_queue <pi, vector<pi>, greater<pi>> q;
queue <int> reverse_path;
int V, E, start, finish, u, v, w, pn;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> V >> E;
		if (V == 0 && E == 0)
			break;
		cin >> start >> finish;
		node = vector<vector<pi>>(V);
		reverse_node = vector<vector<pi>>(V);
		MIN_path = vector<int>(V, 0);
		check = vector<vector<bool>>(V, vector<bool>(V, false));
		check_node = vector<bool>(V, false);
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			node[u].push_back(make_pair(v, w));
			check[u][v] = true;
			reverse_node[v].push_back(make_pair(u, w));
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

		reverse_path.push(finish);
		check_node[finish] = true;
		while(!reverse_path.empty())
		{
			int n = reverse_path.front();
			reverse_path.pop();
			for (pi x : reverse_node[n])
			{
				if (MIN_path[n] - x.second == MIN_path[x.first])
				{
					check[x.first][n] = false;
					if (!check_node[x.first])
					{
						check_node[x.first] = true;
						reverse_path.push(x.first);
					}
				}
			}
		}

		q.push(make_pair(0, start));
		MIN_path = vector<int>(V, 0);
		while (!q.empty())
		{
			pi t = q.top(); // first : distance, second : node
			q.pop();
			if (MIN_path[t.second] < t.first)
				continue;
			for (pi x : node[t.second])
			{
				int next_distance = x.second + t.first;
				if (((MIN_path[x.first] == 0 && x.first != start) || MIN_path[x.first] > next_distance) && check[t.second][x.first])
				{
					MIN_path[x.first] = next_distance;
					q.push(make_pair(MIN_path[x.first], x.first));
				}
			}
		}

		cout << (MIN_path[finish] ? MIN_path[finish] : -1) << "\n";
	}

	return 0;
}