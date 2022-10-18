#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <pair<int, int>> segtree;
vector <int> lazy;
int cnt = 0;

void DFS(int n)
{
	query[n].first = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] == 0)
		return;
	else
	{
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		else
			segtree[n].first += lazy[n];
		lazy[n] = 0;
	}
}

void update_Down(int n, int start, int end, int left, int right, int change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			lazy[n * 2] += change;
			lazy[n * 2 + 1] += change;
		}
		else
			segtree[n].first += change;
	}
	else
	{
		update_Down(n * 2, start, (start + end) / 2, left, right, change);
		update_Down(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
	}
}

void update_Up(int n, int start, int end, int index, int change)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update_Up(n * 2, start, (start + end) / 2, index, change);
		update_Up(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n].second = segtree[n * 2].second + segtree[n * 2 + 1].second;
	}
	else if (start == end && start == index)
		segtree[n].second += change;
}

int find_take(int n, int start, int end, int index)
{
	Lazy(n, start, end);
	if (index < start || index > end)
		return 0;
	if (start == end)
		return segtree[n].first;
	return find_take(n * 2, start, (start + end) / 2, index) + find_take(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int find_give(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].second;
	return find_give(n * 2, start, (start + end) / 2, left, right) + find_give(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, parent, ch, a, x, sum;
	bool dir = false;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<pair<int, int>>((1 << (h + 1)), { 0, 0 });
	lazy = vector<int>((1 << (h + 1)), 0);
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
		cin >> ch;
		if (ch == 1)
		{
			cin >> a >> x;
			if (dir) // 상사 방향
				update_Up(1, 0, N - 1, query[a].first - 1, x);
			else // 부하 방향
				update_Down(1, 0, N - 1, query[a].first - 1, query[a].second - 1, x);
		}
		else if (ch == 2)
		{
			cin >> a;
			sum = 0;
			sum += find_take(1, 0, N - 1, query[a].first - 1);
			sum += find_give(1, 0, N - 1, query[a].first - 1, query[a].second - 1);
			cout << sum << '\n';
		}
		else
			dir = !dir;
	}
	return 0;
}