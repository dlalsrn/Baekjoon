// 네트워크 연결
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cnt = 0;
int sum = 0;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void DFS(vector <vector<pair<int, int>>>& v, vector <bool>& visit, int node)
{
	if (!visit[node])
	{
		visit[node] = true;
		while (cnt < v.size() - 1)
		{
			for (int i = 0; i < v[node].size(); i++)
				if (!visit[v[node][i].first])
					q.push(make_pair(v[node][i].second, v[node][i].first));
			while (!q.empty() && visit[q.top().second])
				q.pop();
			if (q.empty())
				break;
			int next = q.top().second;
			sum += q.top().first;
			cnt++;
			q.pop();
			DFS(v, visit, next);
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int V, E;
	int start, end, value;
	char C;
	cin >> V >> E;
	vector <vector<pair<int, int>>> v(V + 1);
	vector <char> color(V + 1);
	vector <bool> visit(V + 1, false);
	for (int i = 1; i <= V; i++)
	{
		cin >> C;
		color[i] = C;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> value;
		if (color[start] != color[end])
		{
			v[start].push_back(make_pair(end, value));
			v[end].push_back(make_pair(start, value));
		}
	}
	DFS(v, visit, 1);
	if (cnt != V - 1)
		cout << -1;
	else
		cout << sum;
	return 0;
}