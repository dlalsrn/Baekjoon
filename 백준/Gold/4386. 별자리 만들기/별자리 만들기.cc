#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
vector <bool> visit;
int cnt = 0;
float sum = 0;
priority_queue <pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> q;

void DFS(vector <vector<pair<int, float>>>& v, int node)
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
			DFS(v, next);
		}
	}

}

int main(void)
{
	int N;
	float x, y;
	cin >> N;
	vector <pair<float, float>> star;
	vector <vector<pair<int, float>>> dis(N+1);
	visit = vector<bool>(N + 1, false);
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			float distance = sqrt((pow((star[j].first - star[i].first), 2) + pow((star[j].second - star[i].second), 2)));
			dis[i+1].push_back(make_pair(j+1, distance));
			dis[j+1].push_back(make_pair(i+1, distance));
		}
	}

	DFS(dis, 1);

	cout.precision(3);
	cout << sum << '\n';
	return 0;
}