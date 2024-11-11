#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, M;
vector <int> value, segtree;

void init(int n, int start, int end)
{
	if (start == end) segtree[n] = value[start];
	else
	{
		int m = (start + end) / 2;
		init(n * 2, start, m);
		init(n * 2 + 1, m + 1, end);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

void update(int n, int start, int end, int index)
{
	if (start == end) segtree[n] = 0;
	else
	{
		int m = (start + end) / 2;
		if (index <= m) update(n * 2, start, m, index);
		else update(n * 2 + 1, m + 1, end, index);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

int sum(int n, int start, int end, int left, int right)
{
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return segtree[n];
	int m = (start + end) / 2;
	return sum(n * 2, start, m, left, right) + sum(n * 2 + 1, m + 1, end, left, right);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	int h = (int)ceil(log2(N));
	value = vector<int>(N);
	segtree = vector<int>((1 << (h + 1)));

	for (int i = 0; i < N; i++) cin >> value[i];

	init(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int t;
		cin >> t;
		
		int p = sum(1, 0, N - 1, 0, t - 2);
		cout << p + 1 << ' ';
		
		update(1, 0, N - 1, t - 1);
	}

	return 0;
}