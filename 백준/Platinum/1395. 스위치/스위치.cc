// 스위치
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll abc(ll a)
{
	return a < 0 ? -a : a;
}

void segment(vector <ll>& node, vector <pair<ll, bool>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { node[start], false };
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = { 0, false };
	}
}

void lazy(vector <pair<ll, bool>>& tree, ll n, ll start, ll end)
{
	if (tree[n].second == true)
	{
		tree[n].first = abc(tree[n].first - (end - start + 1));
		if (start != end)
		{
			tree[n * 2].second = !tree[n * 2].second;
			tree[n * 2 + 1].second = !tree[n * 2 + 1].second;
		}
		tree[n].second = false;
	}
}

void update(vector <pair<ll, bool>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	lazy(tree, n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		tree[n].first = abc(tree[n].first - (end - start + 1));
		if (start != end)
		{
			tree[n * 2].second = !tree[n * 2].second;
			tree[n * 2 + 1].second = !tree[n * 2 + 1].second;
		}
		return;
	}
	update(tree, n * 2, start, (start + end) / 2, left, right);
	update(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
	tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;

}

ll sum(vector<pair<ll, bool>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	lazy(tree, n, start, end);
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n].first;
	return sum(tree, n * 2, start, (start + end) / 2, left, right) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c, s;
	cin >> N >> M;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, bool>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		node[i] = 0;
	segment(node, segtree, 1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
			update(segtree, 1, 0, N - 1, b - 1, c - 1);
		else
		{
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << s << '\n';
		}
	}
}