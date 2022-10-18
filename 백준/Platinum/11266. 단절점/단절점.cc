#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector <vector<int>> node;
vector <int> order;
set <int> cc;
int cnt = 0, V, E, u, v;

int DFS(int n, bool root)
{
	order[n] = ++cnt;
	int visit_min = order[n];
	int child = 0;

	for (int x : node[n])
	{
		if (order[x])
		{
			visit_min = min(visit_min, order[x]);
			continue;
		}

		child++;
		int child_min = DFS(x, false);

		if (!root && child_min >= order[n])
			cc.insert(n);

		visit_min = min(visit_min, child_min);
	}

	if (root && child >= 2)
		cc.insert(n);

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

	for (int i = 1; i <= V; i++)
		if (!order[i])
			DFS(i, true);

	cout << cc.size() << '\n';
	if (cc.size())
	{
		for (auto i = cc.begin(); i != cc.end(); i++)
			cout << *i << ' ';
	}

	return 0;
}