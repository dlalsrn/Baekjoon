#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <bool> visit; // 방문 여부
vector <vector<int>> node;
vector <int> degree; // 진입 차수
queue <int> order; // 순서

int main(void)
{
	int N, M, A, B;
	cin >> N >> M;
	node = vector<vector<int>>(N + 1);
	visit = vector<bool>(N + 1, false);
	degree = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B; // A번이 B번보다 먼저 서야함
		node[A].push_back(B);
		visit[B] = true;
		degree[B]++; // B의 진입차수 1 증가
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
		int x = order.front();
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