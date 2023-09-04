#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pii = pair<ll, pair<ll, ll>>;

ll N, M, W, U, V, cnt, value = 0;
vector <ll> UN_parent;
vector <ll> segtree;
vector <ll> section;
vector <ll> parent;
vector <ll> sz;
vector <ll> depth;
vector <ll> chain_number;
vector <ll> chain_index;
vector <pii> edge;
vector <pii> ori_edge;
vector <vector<ll>> node;
vector <vector<ll>> chain;
vector <vector<pair<ll, ll>>> mst;

void update(ll n, ll start, ll end, ll index, ll change)
{
	if (start == end)
		segtree[n] = change;
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

ll get_max(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return max(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
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

	if (n != 1)
		update(1, 0, N - 1, cnt, w);
	section[n] = cnt++;
	ll heavy = -1;
	ll weight;
	for (pair<ll, ll> x : mst[n])
	{
		if (x.first != pn && (heavy == -1 || sz[x.first] > sz[heavy]))
		{
			heavy = x.first;
			weight = x.second;
		}
	}
	if (heavy != -1)
		HLD(heavy, n, start_chain, d, weight);

	for (pair<ll, ll> x : mst[n])
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
	cout.tie(0);
	cin >> N >> M;

	ll h = (ll)ceil(log2(N));
	segtree = vector<ll>((1 << (h + 1)), 0);
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
		edge.push_back(make_pair(W, make_pair(U, V)));
		ori_edge.push_back(make_pair(W, make_pair(U, V)));
	}

	sort(all(edge));

	for (pii x : edge)
	{
		if (!sameset(x.second.first, x.second.second))
		{
			value += x.first;
			merge(x.second.first, x.second.second);
			mst[x.second.first].push_back(make_pair(x.second.second, x.first));
			mst[x.second.second].push_back(make_pair(x.second.first, x.first));
		}
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0, 0);

	for (ll i = 0; i < M; i++)
	{
		pii t = ori_edge[i];
		ll u = t.second.first;
		ll v = t.second.second;
		ll w = t.first;
		ll lca = LCA(u, v);
		ll mx = 0;

		while (chain_number[lca] != chain_number[u])
		{
			mx = max(mx, get_max(1, 0, N - 1, section[chain_number[u]], section[u]));
			u = parent[chain_number[u]];
		}
		mx = max(mx, get_max(1, 0, N - 1, section[lca] + 1, section[u]));
		while (chain_number[lca] != chain_number[v])
		{
			mx = max(mx, get_max(1, 0, N - 1, section[chain_number[v]], section[v]));
			v = parent[chain_number[v]];
		}
		mx = max(mx, get_max(1, 0, N - 1, section[lca] + 1, section[v]));

		cout << (value + (w - mx)) << '\n';
	}
}