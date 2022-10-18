#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> segtree;
vector <int> lazy;

void Lazy(int n, int start, int end)
{
	if (lazy[n] != 0)
	{
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		else
			segtree[n] += lazy[n];
		lazy[n] = 0;
	}
}

void update(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
		else
			segtree[n]++;
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}

int get_sum(int n, int start, int end, int index)
{
	Lazy(n, start, end);
	if (start == end)
	{
		int s = segtree[n];
		segtree[n] = 0;
		return s;
	}
	if (index <= (start + end) / 2)
		return get_sum(n * 2, start, (start + end) / 2, index);
	else
		return get_sum(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, l, r;
	cin >> N;
	int h = (int)ceil(log2(100001));
	segtree = vector<int>((1 << (h + 1)), 0);
	lazy = vector<int>((1 << (h + 1)), 0);

	for (int i = 0; i < N; i++)
	{
		cin >> l >> r;
		cout << get_sum(1, 0, 100000, l) + get_sum(1, 0, 100000, r) << '\n';
		update(1, 0, 100000, l + 1, r - 1);
	}
	return 0;
}