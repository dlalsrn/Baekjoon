#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <pair<int, int>> segtree;
vector<vector<int>> node;
vector<pair<int, int>> query;
vector <pair<int, int>> value;
vector <bool> visit;
int cnt = 0;

void DFS(int n)
{
	visit[n] = true;
	query[n].first = ++cnt;
	value[cnt].second = value[n].first;
	for (int i = 0; i < node[n].size(); i++)
		if (!visit[node[n][i]])
			DFS(node[n][i]);
	query[n].second = cnt;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n].first = value[start + 1].second;
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n].first = segtree[n * 2].first ^ segtree[n * 2 + 1].first;
	}
}

void lazy(int n, int start, int end)
{
	if (segtree[n].second != 0)
	{
		if ((end - start + 1) % 2 == 1)
			segtree[n].first ^= segtree[n].second;
		if (start != end)
		{
			segtree[n * 2].second ^= segtree[n].second;
			segtree[n * 2 + 1].second ^= segtree[n].second;
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
		if ((end - start + 1) % 2 == 1)
			segtree[n].first ^= change;
		if (start != end)
		{
			segtree[n * 2].second ^= change;
			segtree[n * 2 + 1].second ^= change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n].first = segtree[n * 2].first ^ segtree[n * 2 + 1].first;
	}
}

int find(int n, int start, int end, int left, int right)
{
	lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].first;
	return find(n * 2, start, (start + end) / 2, left, right) ^ find(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, n1, n2, ch, x, y;
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<pair<int, int>>((1 << (h + 1)), {0, 0});
	node = vector<vector<int>>(N + 1);
	query = vector<pair<int, int>>(N + 1);
	value = vector<pair<int, int>>(N + 1);
	visit = vector<bool>(N + 1, false);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	for (int i = 1; i < value.size(); i++)
		cin >> value[i].first;

	DFS(1);
	set_segtree(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> x;
		if (ch == 1)
			cout << find(1, 0, N - 1, query[x].first - 1, query[x].second - 1) << '\n';
		else
		{
			cin >> y;
			update(1, 0, N - 1, query[x].first - 1, query[x].second - 1, y);
		}
	}
	return 0;
}