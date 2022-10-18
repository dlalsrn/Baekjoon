#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

typedef struct
{
	pair<ll, ll> R;
	pair<ll, ll> L;
}LR;

vector<vector<ll>> node;
vector<ll> segtree;
vector<LR> lazy;
vector<ll> sz;
vector<ll> depth;
vector<ll> section;
vector<ll> parent;
vector<ll> chain_number;
vector<ll> chain_index;
vector<vector<ll>> chain;
ll cnt, N, M, ut_cnt, vt_cnt;

void DFS(ll n, ll pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (ll x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n] + 1;
}


void HLD(ll n, ll pn, ll start_chain, ll d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	section[n] = cnt++;
	ll heavy = -1;
	for (ll x : node[n])
		if (x != pn && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;
	if (heavy != -1)
		HLD(heavy, n, start_chain, d);

	for (ll x : node[n])
		if (x != pn && x != heavy)
			HLD(x, n, x, d + 1);
}

ll LCA(ll u, ll v)
{
	while (chain_number[u] != chain_number[v])
	{
		if (depth[u] > depth[v])
		{
			ut_cnt += chain_index[u] + 1;
			u = parent[chain_number[u]];
		}
		else
		{
			vt_cnt += chain_index[v] + 1;
			v = parent[chain_number[v]];
		}
	}
	if (chain_index[u] > chain_index[v])
	{
		ut_cnt += chain_index[u] - chain_index[v];
		return v;
	}
	else
	{
		vt_cnt += chain_index[v] - chain_index[u];
		return u;
	}
}

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n].L.first != 0 || lazy[n].R.first != 0)
	{
		if (start != end)
		{
			lazy[n * 2].R.first += lazy[n].R.first;
			lazy[n * 2 + 1].R.first += (lazy[n].R.first - (lazy[n].R.second * (((start + end) / 2 + 1) - start)));
			lazy[n * 2].R.second += lazy[n].R.second;
			lazy[n * 2 + 1].R.second += lazy[n].R.second;

			lazy[n * 2].L.first += (lazy[n].L.first - (lazy[n].L.second * (end - (start + end) / 2)));
			lazy[n * 2 + 1].L.first += lazy[n].L.first;
			lazy[n * 2].L.second += lazy[n].L.second;
			lazy[n * 2 + 1].L.second += lazy[n].L.second;
		}
		else
		{
			segtree[n] += lazy[n].R.first;
			segtree[n] += lazy[n].L.first;
		}
		lazy[n].R.first = 0;
		lazy[n].R.second = 0;
		lazy[n].L.first = 0;
		lazy[n].L.second = 0;
	}
}

void update_V(ll n, ll start, ll end, ll left, ll right, ll change, ll R)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			lazy[n * 2].L.first += (change - (R - (start + end) / 2));
			lazy[n * 2 + 1].L.first += change;
			lazy[n * 2].L.second++;
			lazy[n * 2 + 1].L.second++;
		}
		else
			segtree[n] += change;
	}
	else
	{
		if (right <= (start + end) / 2)
			update_V(n * 2, start, (start + end) / 2, left, right, change, R);
		else if (left >= (start + end) / 2 + 1)
			update_V(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, R);
		else
		{
			update_V(n * 2, start, (start + end) / 2, left, right, change - (R - (start + end) / 2), (start + end) / 2);
			update_V(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, R);
		}
	}
}

void update_U(ll n, ll start, ll end, ll left, ll right, ll change, ll L)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			lazy[n * 2].R.first += change;
			lazy[n * 2 + 1].R.first += (change - (((start + end) / 2 + 1) - L));
			lazy[n * 2].R.second++;
			lazy[n * 2 + 1].R.second++;
		}
		else
			segtree[n] += change;
	}
	else
	{
		if (right <= (start + end) / 2)
			update_U(n * 2, start, (start + end) / 2, left, right, change, L);
		else if (left >= (start + end) / 2 + 1)
			update_U(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, L);
		else
		{
			update_U(n * 2, start, (start + end) / 2, left, right, change, L);
			update_U(n * 2 + 1, (start + end) / 2 + 1, end, left, right, (change - (((start + end) / 2 + 1) - L)), (start + end) / 2 + 1);
		}
	}
}

ll get_sum(ll n, ll start, ll end, ll index)
{
	Lazy(n, start, end);
	if (index < start || index > end)
		return 0;
	if (start == end)
		return segtree[n];
	if (index <= (start + end) / 2)
		return get_sum(n * 2, start, (start + end) / 2, index);
	else
		return get_sum(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ch, u, v;
	cin >> N;
	ll h = (ll)ceil(log2(N));
	node = vector<vector<ll>>(N + 1);
	segtree = vector<ll>((1 << (h + 1)), 0);
	lazy = vector<LR>((1 << (h + 1)), { { 0, 0 }, {0, 0} });
	sz = vector<ll>(N + 1);
	depth = vector<ll>(N + 1);
	section = vector<ll>(N + 1);
	parent = vector<ll>(N + 1);
	chain_index = vector<ll>(N + 1);
	chain_number = vector<ll>(N + 1);
	chain = vector<vector<ll>>(N + 1);

	for (ll i = 0; i < N- 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		cin >> ch >> u;
		if (ch == 1)
		{
			cin >> v;
			ut_cnt = 0;
			vt_cnt = 0;
			cnt = 0;
			ll t = LCA(u, v);
			while (chain_number[t] != chain_number[u])
			{
				update_U(1, 0, N - 1, section[chain_number[u]], section[u], cnt + chain_index[u], section[chain_number[u]]);
				cnt += chain_index[u] + 1;
				u = parent[chain_number[u]];
			}
			update_U(1, 0, N - 1, section[t], section[u], cnt + chain_index[u] - chain_index[t], section[t]);
			cnt = ut_cnt + vt_cnt;
			while (chain_number[t] != chain_number[v])
			{
				update_V(1, 0, N - 1, section[chain_number[v]], section[v], cnt, section[v]);
				cnt -= (chain_index[v] + 1);
				v = parent[chain_number[v]];
			}
			update_V(1, 0, N - 1, section[t] + 1, section[v], cnt, section[v]);
		}
		else
			cout << get_sum(1, 0, N - 1, section[u]) << '\n';
	}
	return 0;
}