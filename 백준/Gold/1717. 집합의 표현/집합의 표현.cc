#include <iostream>
#include <vector>
using namespace std;

int N, M, ch, u, v;
vector <int> parent;

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void sameset(int x, int y)
{
	x = find(x), y = find(y);
	cout << (x == y ? "YES\n" : "NO\n");
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

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> u >> v;

		if (ch)
			sameset(u, v);
		else
			merge(u, v);
	}

	return 0;
}