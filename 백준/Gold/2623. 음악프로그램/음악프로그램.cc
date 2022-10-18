#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue <int> order;
vector <vector<int>> node;
vector <int> degree;
vector <int> print;

int main(void)
{
	int N, M, n, a, b, temp, cnt = 0;
	cin >> N >> M;
	node = vector<vector<int>>(N + 1);
	degree = vector<int>(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> n >> a;
		for (int j = 0; j < n - 1; j++)
		{
			cin >> b;
			node[a].push_back(b);
			degree[b]++;
			a = b;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (!degree[i])
		{
			order.push(i);
			cnt++;
		}
	}

	while (!order.empty())
	{
		temp = order.front();
		print.push_back(temp);
		order.pop();

		for (int x : node[temp])
		{
			degree[x]--;
			if (!degree[x])
			{
				order.push(x);
				cnt++;
			}
		}
	}
	if (cnt != N)
		cout << 0;
	else
		for (int x : print)
			cout << x << '\n';
	return 0;
}