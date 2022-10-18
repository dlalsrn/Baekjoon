#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <pair<int, int>> segtree;
int cnt = 0;

void DFS(int n)
{
	query[n].first = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void lazy(int n, int start, int end)
{
	if (segtree[n].second == 0)
		return;
	else
	{
		if (start != end)
		{
			segtree[n * 2].second += segtree[n].second;
			segtree[n * 2 + 1].second += segtree[n].second;
		}
		else
			segtree[n].first += segtree[n].second;
		segtree[n].second = 0;
	}
}

void update(int n, int start, int end, int left, int right, int change)
{
	lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			segtree[n * 2].second += change;
			segtree[n * 2 + 1].second += change;
		}
		else
			segtree[n].first += change;
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
	}
}

int find(int n, int start, int end, int index)
{
	lazy(n, start, end);
	if (index < start || index > end)
		return 0;
	if (start == end)
		return segtree[n].first;
	return find(n * 2, start, (start + end) / 2, index) + find(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, parent, ch, a, x;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<pair<int, int>>((1 << (h + 1)), { 0, 0 });
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
			cout << find(1, 0, N - 1, query[a].first - 1) << '\n';
		else
		{
			cin >> x;
			update(1, 0, N - 1, query[a].first - 1, query[a].second - 1, x);
		}
	}
	return 0;
}