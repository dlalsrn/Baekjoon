// 친구비
// 23.08.31
// 분리집합
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int, int>;

int N, M, K, u, v, ans = 0;
vector <int> parent;
vector <int> cost;
priority_queue<pi, vector<pi>, greater<pi>> pq;

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool sameset(int x, int y)
{
	x = find(x), y = find(y);
	return (x == y ? true : false);
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y)
		return;
	parent[y] = x;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> K;

	parent = vector<int>(N + 1);
	cost = vector<int>(N + 1);

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		pq.push(make_pair(cost[i], i));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		merge(u, v);
	}

	while(!pq.empty())
	{
		int n = pq.top().second;
		int c = pq.top().first;
		pq.pop();

		if (!sameset(0, n))
		{
			if (K >= c)
			{
				ans += c;
				K -= c;
				merge(0, n);
			}
			else
			{
				cout << "Oh no";
				return 0;
			}
		}
	}

	cout << ans;
	return 0;
}