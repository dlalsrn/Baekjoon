// 중앙값 측정
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
	int N, K;
	ll sum = 0;
	cin >> N >> K;
	vector <ll> node(N);
	int h = (int)ceil(log2(65536));
	vector <ll> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(segtree, 1, 0, 65535);
	for (int i = 0; i < N; i++)
	{
		if (i < K - 1)
			update(segtree, 1, 0, 65535, node[i], 1);
		else
		{
			update(segtree, 1, 0, 65535, node[i], 1);
			sum += find(segtree, 1, 0, 65535, (K + 1) / 2);
			update(segtree, 1, 0, 65535, node[i - K + 1], -1);
		}
	}
	cout << sum;
	return 0;
}