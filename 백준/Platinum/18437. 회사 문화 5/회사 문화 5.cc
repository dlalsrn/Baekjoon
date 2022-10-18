#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <pair<int, int>> segtree;
int cnt = 0;

void init_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n].first = 1;
	else
	{
		init_segtree(n * 2, start, (start + end) / 2);
		init_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n].first = segtree[n * 2].first + segtree[n * 2 + 1].first;
	}
}

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
		if (segtree[n].second == 1)
			segtree[n].first = end - start + 1;
		else
			segtree[n].first = 0;
		if (start != end)
		{
			segtree[n * 2].second = segtree[n].second;
			segtree[n * 2 + 1].second = segtree[n].second;
		}
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
		if (change == 1)
			segtree[n].first = end - start + 1;
		else
			segtree[n].first = 0;
		if (start != end)
		{
			segtree[n * 2].second = change;
			segtree[n * 2 + 1].second = change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n].first = segtree[n * 2].first + segtree[n * 2 + 1].first;
	}
}

int find(int n, int start, int end, int left, int right)
{
	lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].first;
	return find(n * 2, start, (start + end) / 2, left, right) + find(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, parent, ch, a;
	cin >> N;
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


	init_segtree(1, 0, N - 1);
	DFS(1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a;
		if (ch == 1) // 켜기
			update(1, 0, N - 1, query[a].first, query[a].second - 1, 1);
		else if (ch == 2) // 끄기
			update(1, 0, N - 1, query[a].first, query[a].second - 1, -1);
		else
			cout << find(1, 0, N - 1, query[a].first, query[a].second - 1) << '\n';
	}
	return 0;
}