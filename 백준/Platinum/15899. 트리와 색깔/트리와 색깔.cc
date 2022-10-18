#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define be(v) v.begin(), v.end()
#define MOD 1000000007
using namespace std;
vector <vector<int>> segtree; // 세그트리
vector <vector<int>> node; // 간선
vector <pair<int, int>> query; // 오일러 구간
vector <pair<int, int>> color;
vector <bool> visit;
int cnt = 0;
long long sum = 0;

void DFS(int n)
{
	visit[n] = true;
	query[n].first = ++cnt;
	color[cnt].second = color[n].first;
	for (int i = 0; i < node[n].size(); i++)
		if (!visit[node[n][i]])
			DFS(node[n][i]);
	query[n].second = cnt;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n].push_back(color[start+1].second);
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n].resize(segtree[n * 2].size() + segtree[n * 2 + 1].size());
		merge(be(segtree[n * 2]), be(segtree[n * 2 + 1]), segtree[n].begin());
	}
}

int find(int n, int start, int end, int left, int right, int C)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return upper_bound(be(segtree[n]), C) - segtree[n].begin();
	return find(n * 2, start, (start + end) / 2, left, right, C) + find(n * 2 + 1, (start + end) / 2 + 1, end, left, right, C);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, C, n1, n2, c;
	cin >> N >> M >> C;
	int h = (int)ceil(log2(N));
	segtree = vector<vector<int>>((1 << (h + 1)));
	node = vector<vector<int>>(N + 1);
	query = vector<pair<int, int>>(N + 1);
	color = vector<pair<int, int>>(N + 1);
	visit = vector<bool>(N + 1, false);

	for (int i = 1; i < color.size(); i++)
		cin >> color[i].first;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	DFS(1);
	set_segtree(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> c;
		sum = (sum + find(1, 0, N - 1, query[n1].first - 1, query[n1].second - 1, c)) % MOD;
	}
	cout << sum << '\n';

	return 0;
}