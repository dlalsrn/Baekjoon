// LCA
// 트리의 최소 공통 조상을 찾는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> node;
vector<int> parent;
vector<int> level;

int lca(int n1, int n2)
{
	// n1을 기준으로 코드를 진행하기 위해 n2의 level이 더 크면 swap
	if (level[n1] < level[n2])
		swap(n1, n2);

	// 두 정점의 level을 맞춰줌
	while (level[n1] != level[n2])
		n1 = parent[n1];

	while (n1 != n2)
	{
		n1 = parent[n1];
		n2 = parent[n2];
	}

	return n1;
}

void set_tree(int n, int pn)
{
	parent[n] = pn;
	level[n] = level[pn] + 1;

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn)
			set_tree(node[n][i], n);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, n1, n2;
	cin >> N;
	node = vector<vector<int>>(N + 1);
	level = vector<int>(N + 1, 0);
	parent = vector<int>(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	set_tree(1, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> n2;
		cout << lca(n1, n2) << '\n';
	}

	return 0;
}