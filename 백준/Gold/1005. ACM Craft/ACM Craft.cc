#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, u, v, x, ans, last;
vector <vector<int>> node;
vector <int> build;
vector <int> mx_time;
vector <int> degree;
queue <int> q;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;

		node = vector<vector<int>>(N + 1);
		degree = vector<int>(N + 1, 0);
		build = vector<int>(N + 1);
		mx_time = vector<int>(N + 1, 0);
		q = queue<int>();
		ans = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> x;
			build[i + 1] = x;
		}

		for (int i = 0; i < M; i++)
		{
			cin >> u >> v;
			node[u].push_back(v);
			degree[v]++;
		}

		cin >> last;

		for (int i = 0; i < N; i++)
		{
			if (!degree[i + 1])
				q.push(i + 1);
		}

		while (!q.empty())
		{
			if (q.front() == last)
			{
				ans = mx_time[q.front()] + build[q.front()];
				break;
			}

			int mx = 0;

			int n = q.front();
			q.pop();
			for (int next : node[n])
			{
				mx_time[next] = max(mx_time[next], mx_time[n] + build[n]);
				if (!(--degree[next]))
					q.push(next);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}