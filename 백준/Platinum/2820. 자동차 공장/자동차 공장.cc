#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <vector<int>> node;
vector <pair<int, int>> query;
vector <int> money;
vector <pair<int, int>> segtree;
int cnt = 0;
void DFS(int);
void set_segtree(int, int, int, int, int);

void DFS(int n)
{
	query[n].first = ++cnt;
	set_segtree(1, 0, node.size()-1, cnt, money[n]);
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void set_segtree(int n, int start, int end, int index, int cash)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		set_segtree(n * 2, start, (start + end) / 2, index, cash);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end, index, cash);
	}
	else if (start == end && start == index)
		segtree[n].first = cash;
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
	int N, M, cash, parent, a, x;
	char ch;
	cin >> N >> M;
	int h = (int)ceil(log2(N + 1));
	segtree = vector<pair<int, int>>((1 << (h + 1)), {0, 0});
	node = vector<vector<int>>(N+1);
	query = vector<pair<int, int>>(N + 1);
	money = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> cash;
		if (i == 1)
			money[i] = cash;
		else
		{
			cin >> parent;
			money[i] = cash;
			node[parent].push_back(i);
		}
	}
	DFS(1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a;
		if (ch == 'u')
			cout << find(1, 0, N, query[a].first) << '\n';
		else
		{
			cin >> x;
			update(1, 0, N, query[a].first + 1, query[a].second, x);
		}
	}
	return 0;
}
