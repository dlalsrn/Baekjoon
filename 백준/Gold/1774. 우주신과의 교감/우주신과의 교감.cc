#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using pdii = pair<double, pair<int, int>>;
using pi = pair<int, int>;

double N, M, u, v;
double ans = 0.0;
vector <pi> node;
vector <int> parent;
priority_queue <pdii, vector<pdii>, greater<pdii>> pq;

int find(int x)
{
	if (x == parent[x])
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

	cin >> N >> M;

	parent = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
	{
		cin >> u >> v;
		node.push_back(make_pair(u, v));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			double x = node[i].first - node[j].first;
			double y = node[i].second - node[j].second;
			pq.push(make_pair(sqrt(x * x + y * y), make_pair(i + 1, j + 1)));
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		merge(u, v);
	}

	while (!pq.empty())
	{
		double w = pq.top().first;
		u = pq.top().second.first;
		v = pq.top().second.second;
		pq.pop();

		if (!sameset(u, v))
		{
			merge(u, v);
			ans += w;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}