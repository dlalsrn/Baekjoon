// 정점들의 거리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> node;
vector<pair<int, int>> parent; // 부모 노드, 거리
vector<int> level;
int sum;

void set_tree(int n, int pn, int value)
{
	parent[n] = make_pair(pn, value);
	level[n] = level[pn] + 1;

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i].first != pn)
			set_tree(node[n][i].first, n, node[n][i].second);
}

int dis(int n1, int n2)
{
	if (level[n1] < level[n2])
		swap(n1, n2);

	while (level[n1] != level[n2])
	{
		sum += parent[n1].second;
		n1 = parent[n1].first;
	}

	while (n1 != n2)
	{
		sum += parent[n1].second + parent[n2].second;
		n1 = parent[n1].first;
		n2 = parent[n2].first;
	}

	return sum;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, n1, n2, edge;
	cin >> N;
	node = vector<vector<pair<int, int>>>(N + 1);
	parent = vector<pair<int, int>>(N + 1);
	level = vector<int>(N + 1, 0);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2 >> edge;
		node[n1].push_back(make_pair(n2, edge));
		node[n2].push_back(make_pair(n1, edge));
	}

	set_tree(1, 0, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		sum = 0;
		cin >> n1 >> n2;
		cout << dis(n1, n2) << '\n';
	}

	return 0;
}