#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct
{
	int MX;
	int MN;
}Node;

vector <Node> segtree;
vector <int> lazy;

void Lazy(int n, int start, int end)
{
	if (lazy[n] != -1)
	{
		segtree[n].MX = lazy[n];
		segtree[n].MN = lazy[n];
		if (start != end)
		{
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = -1;
	}
}

void update_max(int n, int start, int end, int left, int right, int h)
{
	Lazy(n, start, end);
	if (right < start || left > end || segtree[n].MN >= h)
		return;
	if (left <= start && end <= right && segtree[n].MX < h)
	{
		segtree[n].MX = h;
		segtree[n].MN = h;
		if (start != end)
		{
			lazy[n * 2] = h;
			lazy[n * 2 + 1] = h;
		}
	}
	else
	{
		update_max(n * 2, start, (start + end) / 2, left, right, h);
		update_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right, h);
		segtree[n].MX = max(segtree[n * 2].MX, segtree[n * 2 + 1].MX);
		segtree[n].MN = min(segtree[n * 2].MN, segtree[n * 2 + 1].MN);
	}
}

void update_min(int n, int start, int end, int left, int right, int h)
{
	Lazy(n, start, end);
	if (right < start || left > end || segtree[n].MX <= h)
		return;
	if (left <= start && end <= right && segtree[n].MN > h)
	{
		segtree[n].MX = h;
		segtree[n].MN = h;
		if (start != end)
		{
			lazy[n * 2] = h;
			lazy[n * 2 + 1] = h;
		}
	}
	else
	{
		update_min(n * 2, start, (start + end) / 2, left, right, h);
		update_min(n * 2 + 1, (start + end) / 2 + 1, end, left, right, h);
		segtree[n].MX = max(segtree[n * 2].MX, segtree[n * 2 + 1].MX);
		segtree[n].MN = min(segtree[n * 2].MN, segtree[n * 2 + 1].MN);
	}
}

void get_height(int n, int start, int end, int index)
{
	Lazy(n, start, end);
	if (start == end)
	{
		cout << segtree[n].MX << '\n';
		return;
	}
	if (index <= (start + end) / 2)
		get_height(n * 2, start, (start + end) / 2, index);
	else
		get_height(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, ch, l, r, h;
	cin >> N >> M;
	h = (int)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)), { 0, 0 });
	lazy = vector<int>((1 << (h + 1)), -1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> l >> r >> h;
		if (ch == 1)
			update_max(1, 0, N - 1, l, r, h);
		else
			update_min(1, 0, N - 1, l, r, h);
	}

	for (int i = 0; i < N; i++)
		get_height(1, 0, N - 1, i);
	return 0;
}