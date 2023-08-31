// 여행 가자
// 23.08.31
// 분리집합
#include <iostream>
#include <vector>
using namespace std;

int N, M, ch, u, v;
vector <int> parent;
vector <int> travel;

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

	cin >> N >> M;

	parent = vector<int>(N + 1);
	travel = vector<int>(M);

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			if (i == j)
				continue;
			if (ch)
				merge(i + 1, j + 1);
		}
	}

	for (int i = 0; i < M; i++)
		cin >> travel[i];

	for (int i = 0; i < M - 1; i++)
	{
		if (!sameset(travel[i], travel[i + 1]))
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}