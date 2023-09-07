#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, D, x, ans = 0, mx;
vector <int> segtree;
vector <int> mod;

void update(int n, int start, int end, int index, int change)
{
	if (index < start || end < index)
		return;
	if (start == end)
		segtree[n] = max(segtree[n], change);
	else
	{
		int mid = (start + end) >> 1;
		update(n * 2, start, mid, index, change);
		update(n * 2 + 1, mid + 1, end, index, change);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

int get_max(int n, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	int mid = (start + end) >> 1;
	return max(get_max(n * 2, start, mid, left, right), get_max(n * 2 + 1, mid + 1, end, left, right));
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K >> D;
	int h = (int)ceil(log2(500001));
	segtree = vector<int>((1 << (h + 1)), 0);
	mod = vector<int>(500001, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		mx = max(mod[x % K], get_max(1, 0, 500000, max(1, x - D), min(500000, x + D)));
		update(1, 0, 500000, x, mx + 1);
		mod[x % K] = max(mod[x % K], mx + 1);
		ans = max(ans, mx + 1);
	}

	cout << ans;

	return 0;
}