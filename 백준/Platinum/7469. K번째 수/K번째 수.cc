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

ll sum(vector<vector<ll>>& tree, ll n, ll start, ll end, ll left, ll right, ll num)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
	{
		ll cnt = lower_bound(tree[n].begin(), tree[n].end(), num) - tree[n].begin();
		return cnt;
	}
	return sum(tree, n * 2, start, (start + end) / 2, left, right, num) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right, num);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c;
	cin >> N >> M;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <vector<ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		ll l = -1e9;
		ll r = 1e9;
		ll mid;
		ll ans = -1e9;
		while (l <= r)
		{
			mid = (l + r) / 2;
			ll q = sum(segtree, 1, 0, N - 1, a - 1, b - 1, mid);
			if (q < c)
			{
				ans = max(ans, mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}