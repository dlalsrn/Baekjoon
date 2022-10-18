#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> node;
vector<pair<int, int>> query;
vector <bool> visit;
vector <int> segtree;
vector <int> level;
int cnt = 0;

void DFS(int n, int pn)
{
	visit[n] = true;
	level[n] = level[pn] + 1;
	query[n].first = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (!visit[node[n][i]])
			DFS(node[n][i], n);
	query[n].second = cnt;
}

void update(int n, int start, int end, int index)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
	else
		segtree[n]++;
}

int sum(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return sum(n * 2, start, (start + end) / 2, left, right) + sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, C, n1, n2, ch, a;
	long long s;
	cin >> N >> C;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), 0);
	node = vector<vector<int>>(N + 1);
	level = vector<int>(N + 1, 0);
	query = vector<pair<int, int>>(N + 1);
	visit = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	DFS(C, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> a;
		if (ch == 1)
			update(1, 0, N - 1, query[a].first - 1);
		else
		{
			s = (long long)sum(1, 0, N - 1, query[a].first - 1, query[a].second - 1) * (long long)level[a];
			cout << s << '\n';
		}
	}
	return 0;
}