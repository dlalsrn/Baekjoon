#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector <vector<int>> node;
vector <vector<int>> SCC;
vector <int> order;
vector <bool> visit;
vector <bool> include_ssc;
stack <int> s; // DFS시 방문하는 노드
int cnt = 0, V, E, u, v;

int DFS(int n)
{
	visit[n] = true;
	order[n] = ++cnt;
	s.push(n);

	int mx = cnt;
	for (int x : node[n])
	{
		if (!visit[x])
			mx = min(mx, DFS(x));
		else if (!include_ssc[x])
			mx = min(mx, order[x]);
	}

	if (order[n] == mx)
	{
		vector<int> temp;
		while (true)
		{
			int t = s.top();
			s.pop();
			temp.push_back(t);
			include_ssc[t] = true;
			if (t == n)
				break;
		}
		sort(temp.begin(), temp.end());
		SCC.push_back(temp);
	}

	return mx;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	node = vector<vector<int>>(V + 1);
	order = vector<int>(V + 1);
	visit = vector<bool>(V + 1, false);
	include_ssc = vector<bool>(V + 1, false);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
	}

	for (int i = 1; i <= V; i++)
		if (!visit[i])
			DFS(i);
	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int x : SCC[i])
			cout << x << ' ';
		cout << -1 << '\n';
	}
	return 0;
}