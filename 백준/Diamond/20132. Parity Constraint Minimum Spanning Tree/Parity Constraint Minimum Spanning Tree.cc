#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll N, M, W, U, V, cnt, value = 0, ans_even = 1e18, ans_odd = 1e18;
vector <ll> UN_parent;
vector <pl> segtree;
vector <ll> lazy;
vector <ll> section;
vector <ll> parent;
vector <ll> sz;
vector <ll> depth;
vector <ll> chain_number;
vector <ll> chain_index;
vector <tuple<ll, ll, ll>> edge;
vector <tuple<ll, ll, ll>> not_used_edge;
vector <vector<ll>> node;
vector <vector<ll>> chain;
vector <vector<pl>> mst;

pl upt(pl a, pl b)
{
	return make_pair(max(a.first, b.first), max(a.second, b.second));
}

void update(ll n, ll start, ll end, ll index, ll change)
{
	if (start == end)
		segtree[n] = (change & 1) ? make_pair((ll)0, change) : make_pair(change, (ll)0);
	else
	{
		ll mid = (start + end) >> 1;
		if (index <= mid)
			update(n << 1, start, mid, index, change);
		else
			update((n << 1) + 1, mid + 1, end, index, change);
		segtree[n] = upt(segtree[n << 1], segtree[(n << 1) + 1]);

	}
}

pl get(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return make_pair(0, 0);
	if (left <= start && end <= right)
		return segtree[n];
	ll mid = (start + end) >> 1;
	return upt(get(n << 1, start, mid, left, right), get((n << 1) + 1, mid + 1, end, left, right));
}

void DFS(ll n, ll pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (pair<ll, ll> x : mst[n])
		if (x.first != pn)
			DFS(x.first, n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(ll n, ll pn, ll start_chain, ll d, ll w)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	update(1, 0, N - 1, cnt, w);
	section[n] = cnt++;
	ll heavy = -1;
	ll weight;
	for (pl x : mst[n])
	{
		if (x.first != pn && (heavy == -1 || sz[x.first] > sz[heavy]))
		{
			heavy = x.first;
			weight = x.second;
		}
	}
	if (heavy != -1)
		HLD(heavy, n, start_chain, d, weight);

	for (pl x : mst[n])
		if (x.first != pn && x.first != heavy)
			HLD(x.first, n, x.first, d + 1, x.second);
}

ll LCA(ll X, ll Y)
{
	while (chain_number[X] != chain_number[Y])
	{
		if (depth[X] > depth[Y])
			X = parent[chain_number[X]];
		else
			Y = parent[chain_number[Y]];
	}
	return chain_index[X] > chain_index[Y] ? Y : X;
}

ll find(ll x)
{
	if (UN_parent[x] == x)
		return x;
	return UN_parent[x] = find(UN_parent[x]);
}

void merge(ll x, ll y)
{
	x = find(x), y = find(y);
	if (x == y)
		return;
	UN_parent[y] = x;
}

bool sameset(ll x, ll y)
{
	x = find(x), y = find(y);
	return (x == y ? true : false);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	ll h = (ll)ceil(log2(N));
	segtree = vector<pl>((1 << (h + 1)), {0, 0});
	node = vector <vector<ll>>(N + 1);
	mst = vector <vector<pair<ll, ll>>>(N + 1);
	section = vector<ll>(N + 1);
	parent = vector<ll>(N + 1);
	sz = vector<ll>(N + 1);
	depth = vector<ll>(N + 1);
	chain_number = vector<ll>(N + 1);
	chain_index = vector<ll>(N + 1);
	chain = vector<vector<ll>>(N + 1);
	UN_parent = vector<ll>(N + 1);

	for (ll i = 1; i <= N; i++)
		UN_parent[i] = i;

	for (ll i = 0; i < M; i++)
	{
		cin >> U >> V >> W;
		edge.push_back({ W, U, V });
	}

	sort(all(edge));

	for (auto [w, u, v] : edge) // W, U, V
	{
		if (!sameset(u, v))
		{
			value += w;
			merge(u, v);
			mst[u].push_back(make_pair(v, w));
			mst[v].push_back(make_pair(u, w));
		}
		else
			not_used_edge.push_back({ w, u, v });
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0, 0);

	if (value & 1)
		ans_odd = value;
	else
		ans_even = value;

	for (auto [w, u, v] : not_used_edge)
	{
		ll lca = LCA(u, v);
		pl t = make_pair(0, 0);

		while (chain_number[lca] != chain_number[u])
		{
			t = upt(t, get(1, 0, N - 1, section[chain_number[u]], section[u]));
			u = parent[chain_number[u]];
		}
		t = upt(t, get(1, 0, N - 1, section[lca] + 1, section[u]));

		while (chain_number[lca] != chain_number[v])
		{
			t = upt(t, get(1, 0, N - 1, section[chain_number[v]], section[v]));
			v = parent[chain_number[v]];
		}
		t = upt(t, get(1, 0, N - 1, section[lca] + 1, section[v]));

		if (value & 1) // 기존 mst가 홀수
		{
			if (w & 1) // 대체 간선이 홀수
			{
				if (t.first)
					ans_even = min(ans_even, value - t.first + w);
			}
			else // 대체 간선이 짝수
				if (t.second)
					ans_even = min(ans_even, value - t.second + w);
		}
		else // 기존 mst가 짝수
		{
			if (w & 1) // 대체 간선이 홀수
			{
				if (t.first)
					ans_odd = min(ans_odd, value - t.first + w);
			}
			else // 대체 간선이 짝수
				if (t.second) // 짝 - 홀 + 짝
					ans_odd = min(ans_odd, value - t.second + w);
		}
	}

	cout << (ans_odd == 1e18 ? -1 : ans_odd) << ' ';
	cout << (ans_even == 1e18 ? -1 : ans_even) << '\n';

	return 0;
}