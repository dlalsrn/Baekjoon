#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector <int> segtree;
vector <int> lazy;
vector <int> point;
vector <pair<int, int>> com;

void Lazy(int n, int start, int end)
{
	if (lazy[n] != 0)
	{
		segtree[n] = max(segtree[n], lazy[n]);
		if (start != end)
		{
			lazy[n * 2] = max(lazy[n*2], lazy[n]);
			lazy[n * 2 + 1] = max(lazy[n*2+1], lazy[n]);
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
		segtree[n] = max(segtree[n], change);
		if (start != end)
		{
			lazy[n * 2] = max(lazy[n*2], change);
			lazy[n * 2 + 1] = max(lazy[n*2+1], change);
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

int get_max(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return max(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int W, D, N;
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		cin >> W >> D;
		point.push_back(D);
		point.push_back(W + D - 1);
		com.push_back(make_pair(W, D));
	}

	sort(point.begin(), point.end());
	point.erase(unique(point.begin(), point.end()), point.end());

	int h = (int)ceil(log2(point.size()));
	segtree = vector<int>((1 << (h + 1)), 0);
	lazy = vector<int>((1 << (h + 1)), 0);

	for (int i = 0; i < N; i++)
	{
		int l = lower_bound(point.begin(), point.end(), com[i].second) - point.begin();
		int r = lower_bound(point.begin(), point.end(), com[i].first + com[i].second - 1) - point.begin();
		int mx = get_max(1, 0, point.size() - 1, l, r);
		update(1, 0, point.size() - 1, l, r, mx + 1);
	}
	cout << get_max(1, 0, point.size() - 1, 0, point.size() - 1);

	return 0;
}