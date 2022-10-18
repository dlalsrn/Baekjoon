#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector<int>> node;
vector <int> order;
vector <pair<int, int>> edge;
int V, E, v, u, cnt = 0;

int DFS(int n, int pn)
{
	order[n] = ++cnt;
	int visit_min = order[n];

	for (int x : node[n])
	{
		if (x != pn)
		{
			if (order[x])
				visit_min = min(visit_min, order[x]);
			else
			{
				int child_min = DFS(x, n);
				if (child_min > order[n])
					edge.push_back(x < n ? make_pair(x, n) : make_pair(n, x));
				visit_min = min(visit_min, child_min);
			}
		}
	}

	return visit_min;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	node = vector<vector<int>>(V + 1);
	order = vector<int>(V + 1, 0);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, 0);
	sort(edge.begin(), edge.end());

	cout << edge.size() << '\n';
	if (edge.size())
		for (int i = 0; i < edge.size(); i++)
			cout << edge[i].first << ' ' << edge[i].second << '\n';

	return 0;
}