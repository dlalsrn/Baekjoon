#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cnt = 0;
long long sum = 0;
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
	int V;
	int value;
	cin >> V;
	vector <vector<pair<int, int>>> v(V + 1);
	vector <bool> visit(V + 1, false);
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			cin >> value;
			if (j > i)
			{
				v[i].push_back(make_pair(j, value));
				v[j].push_back(make_pair(i, value));
			}
		}
	}
	DFS(v, visit, 1);
	cout << sum;
	return 0;
}