#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <int> segtree;
int cnt = 0;

void DFS(int n)
{
	query[n].first = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void update(int n, int start, int end, int index, int change)
{
	if (index < start || index > end)
		return;

	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
	else
		segtree[n] += change;
}

int find(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return find(n * 2, start, (start + end) / 2, left, right) + find(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, parent, ch, a, x;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 0);
	node = vector<vector<int>>(N + 1);
	query = vector<pair<int, int>>(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> parent;
		if (i == 1)
			continue;
		node[parent].push_back(i);
	}

	DFS(1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a;
		if (ch == 2)
			cout << find(1, 0, N - 1, query[a].first - 1, query[a].second - 1) << '\n';
		else
		{
			cin >> x;
			update(1, 0, N - 1, query[a].first - 1, x);
		}
	}
	return 0;
}