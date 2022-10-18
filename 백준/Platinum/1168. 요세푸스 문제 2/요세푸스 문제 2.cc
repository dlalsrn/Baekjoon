// 요세푸스 문제 2
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = 1;
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
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

ll sum(vector<ll>& tree, ll n, ll start, ll end, ll index)
{
	if (start == end)
		return start;
	if (tree[n * 2] >= index)
		return sum(tree, n * 2, start, (start + end) / 2, index);
	else
	{
		index -= tree[n * 2];
		return sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

int main(void)
{
	int N, K, k, cnt = 0;
	ll a, b, c, s;
	cin >> N >> k;
	K = k;
	int h = (int)ceil(log2(N));
	vector <ll> segtree((1 << (h + 1)));
	segment(segtree, 1, 1, N);
	cout << "<";
	for (int i = N; i > 0; i--)
	{
		if (K - cnt >= i)
		{
			K = (K - cnt) % i;
			if (K == 0)
				K = i;
			cnt = 0;
		}
		s = sum(segtree, 1, 1, N, K - cnt);
		cout << s;
		if (i == 1)
			break;
		cout << ", ";
		update(segtree, 1, 1, N, s, -1);
		K += k;
		cnt++;
	}
	cout << ">";
	return 0;
}