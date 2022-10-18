#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define be(v) v.begin(), v.end()
using namespace std;
vector <vector<int>> segtree; // 세그트리
vector <vector<int>> node; // 간선
vector <pair<int, int>> query; // 오일러 구간
vector <pair<int, int>> value;
int cnt = 0;

void DFS(int n)
{
	query[n].first = ++cnt;
	value[cnt].second = value[n].first;
	for (int i = 0; i < node[n].size(); i++)
		DFS(node[n][i]);
	query[n].second = cnt;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n].push_back(value[start + 1].second);
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n].resize(segtree[n * 2].size() + segtree[n * 2 + 1].size());
		merge(be(segtree[n * 2]), be(segtree[n * 2 + 1]), segtree[n].begin());
	}
}

int find(int n, int start, int end, int left, int right, int v)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].end() - upper_bound(be(segtree[n]), v);
	return find(n * 2, start, (start + end) / 2, left, right, v) + find(n * 2 + 1, (start + end) / 2 + 1, end, left, right, v);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, parent;
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<vector<int>>((1 << (h + 1)));
	node = vector<vector<int>>(N + 1);
	query = vector<pair<int, int>>(N + 1);
	value = vector<pair<int, int>>(N + 1);

	for (int i = 1; i < value.size(); i++)
		cin >> value[i].first;

	for (int i = 2; i <= N; i++)
	{
		cin >> parent;
		node[parent].push_back(i);
	}

	DFS(1);
	set_segtree(1, 0, N - 1);

	for (int i = 1; i <= N; i++)
		cout << find(1, 0, N - 1, query[i].first, query[i].second - 1, value[i].first) << '\n';

	return 0;
}