#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define be(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void segment(vector <ll>& node, vector <vector<ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n].push_back(node[start]);
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n].resize(tree[n * 2].size() + tree[n * 2 + 1].size());
		merge(be(tree[n * 2]), be(tree[n * 2 + 1]), tree[n].begin());
	}
}

int sum(vector<vector<ll>>& tree, ll n, ll start, ll end, ll left, ll right, ll k)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n].end() - upper_bound(be(tree[n]), k);
	else
		return sum(tree, n * 2, start, (start + end) / 2, left, right, k) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c, last = 0;
	cin >> N;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <vector<ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		a ^= last;
		b ^= last;
		c ^= last;
		ll t = sum(segtree, 1, 0, N - 1, a - 1, b - 1, c);
		cout << t << '\n';
		last = t;
	}
}