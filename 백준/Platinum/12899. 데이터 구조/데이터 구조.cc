#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = 0;
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = 0;
	}
}

void update(vector <ll>& tree, ll n, ll start, ll end, ll index, ll change)
{
	if (index < start || end < index)
		return;
	if (start != end)
	{
		update(tree, n * 2, start, (start + end) / 2, index, change);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
	else if (start == end && start == index)
		tree[n] += change;
}

ll find(vector<ll>& tree, ll n, ll start, ll end, ll index)
{
	if (start == end)
		return start;
	if (tree[n * 2] >= index)
		return find(tree, n * 2, start, (start + end) / 2, index);
	else
	{
		index -= tree[n * 2];
		return find(tree, n * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, T, X;
	cin >> N;
	int h = (int)ceil(log2(2000001));
	vector <ll> segtree((1 << (h + 1)));
	segment(segtree, 1, 0, 2000000);
	for (int i = 0; i < N; i++)
	{
		cin >> T >> X;
		if (T == 1)
			update(segtree, 1, 0, 2000000, X, 1);
		else
		{
			ll t = find(segtree, 1, 0, 2000000, X);
			cout << t << '\n';
			update(segtree, 1, 0, 2000000, t, -1);
		}
	}
	return 0;
}