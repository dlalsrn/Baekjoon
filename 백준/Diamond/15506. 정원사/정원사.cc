#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K, INF = 1e18, a, b, c, d, e;
vector<priority_queue<ll>> segtree;
vector <ll> mx, cnt;

void update1(ll n, ll start, ll end, ll index, ll h)
{
	if (start == end)
	{
		segtree[start].push(h);
		mx[n] = max(mx[n], segtree[start].top());
		cnt[n] = segtree[start].size();
		return;
	}
	ll mid = (start + end) >> 1;
	if (index <= mid) update1(n * 2, start, mid, index, h);
	else update1(n * 2 + 1, mid + 1, end, index, h);
	cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
	mx[n] = max(mx[n * 2], mx[n * 2 + 1]);
}

void update2(ll n, ll start, ll end, ll left, ll right, ll h)
{
	if (right < start || left > end || mx[n] <= h) return;
	if (start == end)
	{
		while (!segtree[start].empty() && segtree[start].top() > h) segtree[start].pop();
		cnt[n] = segtree[start].size();
		mx[n] = (segtree[start].empty() ? -INF : segtree[start].top());
		return;
	}
	ll mid = (start + end) >> 1;
	update2(n * 2, start, mid, left, right, h);
	update2(n * 2 + 1, mid + 1, end, left, right, h);
	cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
	mx[n] = max(mx[n * 2], mx[n * 2 + 1]);
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end) return 0LL;
	if (left <= start && end <= right) return cnt[n];
	ll mid = (start + end) >> 1;
	return get_sum(n * 2, start, mid, left, right) + get_sum(n * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> K;
	ll h = (ll)ceil(log2(N));
	segtree = vector<priority_queue<ll>>(N);
	mx = vector <ll>((1 << (h + 1)), -INF);
	cnt = vector <ll>((1 << (h + 1)), 0);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d;

		if (a == 1) update1(1, 0, N - 1, c - 1, d - b * K);
		else if (a == 2)
		{
			cin >> e;
			update2(1, 0, N - 1, c - 1, d - 1, e - b * K);
		}
		else cout << get_sum(1, 0, N - 1, c - 1, d - 1) << '\n';
	}

	return 0;
}