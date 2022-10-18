// 정복자
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
	int V, E, t;
	int start, end, value;
	cin >> V >> E >> t;
	vector <vector<pair<int, int>>> v(V + 1);
	vector <bool> visit(V + 1, false);
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> value;
		v[start].push_back(make_pair(end, value));
		v[end].push_back(make_pair(start, value));
	}
	DFS(v, visit, 1);
	cout << sum + ((V-2)*(V-1))/2*t;
	return 0;
}