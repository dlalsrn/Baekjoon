#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <bool> visit;
vector <vector<int>> node;
vector <int> degree;
priority_queue <int, vector<int>, greater<int>> order;

int main(void)
{
	int N, M, A, B, l, r;
	cin >> N >> M;
	node = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1, false);
	degree = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B; // A번을 B번보다 먼저 풀어야함
		node[A].push_back(B);
		visit[B] = true;
		degree[B]++;
	}

	for (int i = 1; i < N; i++)
	{
		if (!visit[i])
		{
			node[i].push_back(i + 1);
			degree[i + 1]++;
		}
	}

	for (int i = 1; i <= N; i++)
		if (!degree[i])
			order.push(i);

	while (!order.empty())
	{
		int x = order.top();
		cout << x << ' ';
		order.pop();
		for (int n : node[x])
		{
			degree[n]--;
			if (!degree[n])
				order.push(n);
		}
	}

	return 0;
}