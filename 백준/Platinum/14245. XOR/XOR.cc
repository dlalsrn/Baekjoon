// XOR
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { node[start], 0 };
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = { tree[n * 2].first ^ tree[n * 2 + 1].first, 0 };
	}
}

void lazy(vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (tree[n].second != 0)
	{
		if ((end - start + 1) % 2 == 1)
			tree[n].first ^= tree[n].second;
		if (start != end)
		{
			tree[n * 2].second ^= tree[n].second;
			tree[n * 2 + 1].second ^= tree[n].second;
		}
		tree[n].second = 0;
	}
}

void update(vector <pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right, ll change)
{
	lazy(tree, n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		if ((end - start + 1) % 2 == 1)
			tree[n].first ^= change;
		if (start != end)
		{
			tree[n * 2].second ^= change;
			tree[n * 2 + 1].second ^= change;
		}
		return;
	}
	update(tree, n * 2, start, (start + end) / 2, left, right, change);
	update(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
	tree[n].first = tree[n * 2].first ^ tree[n * 2 + 1].first;
}

void XOR(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll index)
{
	lazy(tree, n, start, end);
	if (index > end || index < start)
		return;
	if (start == end)
	{
		if (start == index)
			cout << tree[n].first << '\n';
	}
	else
	{
		XOR(tree, n * 2, start, (start + end) / 2, index);
		XOR(tree, n * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c, d;
	cin >> N;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(segtree, 1, 0, N - 1, b, c, d);
		}
		else
		{
			cin >> b;
			XOR(segtree, 1, 0, N - 1, b);
		}
	}
}