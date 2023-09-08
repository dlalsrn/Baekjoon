#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<pair<ll, ll>, ll>;

ll K, N, C, s, e, m, ans = 0;
vector <ll> segtree;
vector <ll> lazy;
priority_queue <pii, vector<pii>, greater<pii>> pq;

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n])
	{
		segtree[n] += lazy[n];
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(ll n, ll start, ll end, ll left, ll right, ll value)
{
	Lazy(n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		segtree[n] += value;
		if (start != end)
		{
			lazy[n * 2] += value;
			lazy[n * 2 + 1] += value;
		}
	}
	else
	{
		int mid = (start + end) >> 1;
		update(n * 2, start, mid, left, right, value);
		update(n * 2 + 1, mid + 1, end, left, right, value);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

ll get_max(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
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

	cin >> K >> N >> C;

	ll h = (ll)ceil(log2(N + 1));
	segtree = vector<ll>((1 << (h + 1)), 0);
	lazy = vector<ll>((1 << (h + 1)));

	for (int i = 0; i < K; i++)
	{
		cin >> s >> e >> m;
		pq.push(make_pair(make_pair(e, s), m));
	}

	while (!pq.empty())
	{
		s = pq.top().first.second;
		e = pq.top().first.first;
		m = pq.top().second;
		pq.pop();

		int mx = get_max(1, 0, N, s, e - 1);
		int mn = min(m, C - mx);
		ans += mn;
		update(1, 0, N, s, e - 1, mn);
	}

	cout << ans;

	return 0;
}