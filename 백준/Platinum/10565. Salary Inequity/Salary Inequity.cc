#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <pair<int, int>> segtree;
vector <pair<int, int>> query;
vector <vector<int>> node;
vector <pair<int, int>> salary;
vector <int> lazy;
int cnt;

pair<int, int> Max_Min(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first > b.first)
	{
		if (a.second > b.second)
			return { a.first, b.second };
		else
			return { a.first, a.second };
	}
	else
	{
		if (a.second > b.second)
			return { b.first, b.second };
		else
			return { b.first, a.second };
	}
}

void DFS(int n)
{
	query[n].first = ++cnt;
	salary[cnt].second = salary[n].first;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = { salary[start + 1].second, salary[start + 1].second };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = Max_Min(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] != 0)
	{
		segtree[n].first += lazy[n];
		segtree[n].second += lazy[n];
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int n, int start, int end, int left, int right, int change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		segtree[n].first += change;
		segtree[n].second += change;
		if (start != end)
		{
			lazy[n * 2] += change;
			lazy[n * 2 + 1] += change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = Max_Min(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

pair<int, int> find(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return {0, 0};
	if (left <= start && end <= right)
		return segtree[n];
	pair<int, int> p1 = find(n * 2, start, (start + end) / 2, left, right);
	pair<int, int> p2 = find(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (p1.first == 0)
		return p2;
	else if (p2.first == 0)
		return p1;
	else
		return Max_Min(p1, p2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, M, parent, money, K;
	char ch;
	cin >> T;

	while (T--)
	{
		cnt = 0;
		cin >> N;
		int h = (int)ceil(log2(N));
		segtree = vector<pair<int, int>>((1 << (h + 1)), { 0, 0 });
		query = vector<pair<int, int>>(N + 1, {0, 0});
		node = vector<vector<int>>(N + 1);
		salary = vector<pair<int, int>>(N + 1, {0, 0});
		lazy = vector<int>((1 << (h + 1)), 0);

		for (int i = 2; i <= N; i++)
		{
			cin >> parent;
			node[parent].push_back(i);
		}
		for (int i = 1; i < salary.size(); i++)
			cin >> salary[i].first;

		DFS(1);
		set_segtree(1, 0, N - 1);

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> ch >> K;
			if (ch == 'Q')
			{
				pair<int, int> temp = find(1, 0, N - 1, query[K].first - 1, query[K].second - 1);
				cout << temp.first - temp.second << '\n';
			}
			else
			{
				cin >> money;
				update(1, 0, N - 1, query[K].first - 1, query[K].second - 1, money);
			}
		}
	}
}