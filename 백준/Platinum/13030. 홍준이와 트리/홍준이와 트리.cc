#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef struct
{
	ll X;
	ll K;
	ll P;
}NODE;

vector <ll> segtree;
vector <NODE> lazy;
vector <vector<ll>> node;
vector <pair<ll, ll>> section;
vector <ll> order;
vector <ll> level;
ll N, Q, p, ch, v, x, k, cnt = 0;

void DFS(ll n, ll pn)
{
	level[n] = level[pn] + 1;
	section[n].first = ++cnt;
	order[cnt] = n;
	for (ll x : node[n])
		DFS(x, n);
	section[n].second = cnt;
}

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n].K || lazy[n].X || lazy[n].P)
	{
		if (start != end)
		{
			lazy[n * 2].X = (lazy[n * 2].X + lazy[n].X) % MOD;
			lazy[n * 2].K = (lazy[n * 2].K + lazy[n].K) % MOD;
			lazy[n * 2].P = (lazy[n * 2].P + lazy[n].P) % MOD;
			lazy[n * 2 + 1].X = (lazy[n * 2 + 1].X + lazy[n].X) % MOD;
			lazy[n * 2 + 1].K = (lazy[n * 2 + 1].K + lazy[n].K) % MOD;
			lazy[n * 2 + 1].P = (lazy[n * 2 + 1].P + lazy[n].P) % MOD;
		}
		else
			segtree[n] = (segtree[n] + (lazy[n].X - (level[order[start + 1]] * lazy[n].K) % MOD + lazy[n].P)) % MOD;
		lazy[n] = { 0, 0, 0 };
	}
}

void update(ll n, ll start, ll end, ll left, ll right, ll x, ll k, ll p)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			lazy[n * 2].X = (lazy[n * 2].X + x) % MOD;
			lazy[n * 2].K = (lazy[n * 2].K + k) % MOD;
			lazy[n * 2].P = (lazy[n * 2].P + p) % MOD;
			lazy[n * 2 + 1].X = (lazy[n * 2 + 1].X + x) % MOD;
			lazy[n * 2 + 1].K = (lazy[n * 2 + 1].K + k) % MOD;
			lazy[n * 2 + 1].P = (lazy[n * 2 + 1].P + p) % MOD;
		}
		else
			segtree[n] = (segtree[n] + (x - (level[order[start + 1]] * k) % MOD + p)) % MOD;
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, x, k, p);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, x, k, p);
	}
}

ll get_value(ll n, ll start, ll end, ll index)
{
	Lazy(n, start, end);
	if (start == end)
		return segtree[n];
	else

	{
		if (index <= (start + end) / 2)
			return get_value(n * 2, start, (start + end) / 2, index);
		else
			return get_value(n * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;

	ll h = (ll)ceil(log2(N));
	segtree = vector<ll>((1 << (h + 1)), 0);
	lazy = vector<NODE>((1 << (h + 1)), { 0, 0, 0 });
	node = vector<vector<ll>>(N + 1);
	level = vector<ll>(N + 1, -1);
	section = vector<pair<ll, ll>>(N + 1);
	order = vector<ll>(N + 1);

	for (int i = 2; i <= N; i++)
	{
		cin >> p;
		node[p].push_back(i);
	}

	DFS(1, 0);

	for (int i = 0; i < Q; i++)
	{
		cin >> ch >> v;
		if (ch == 1)
		{
			cin >> x >> k;
			update(1, 0, N - 1, section[v].first - 1, section[v].second - 1, x, k, level[v] * k % MOD);
		}
		else
		{
			ll sum = get_value(1, 0, N - 1, section[v].first - 1) % MOD;
			if (sum < 0)
				sum += MOD;
			cout << sum << '\n';
		}
	}

	return 0;
}