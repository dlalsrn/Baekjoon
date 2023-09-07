#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

typedef struct
{
	ll mn, mx, sum;
}NODE;

ll N, M, ch, L, R, X;
vector <NODE> segtree;
vector <ll> ary;
vector <ll> add_lazy;
vector <ll> sqrt_lazy;

NODE upt(NODE a, NODE b)
{
	return { min(a.mn, b.mn), max(a.mx, b.mx), a.sum + b.sum };
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { ary[start], ary[start], ary[start] };
	else
	{
		ll mid = (start + end) >> 1;
		set_segtree(n * 2, start, mid);
		set_segtree(n * 2 + 1, mid + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void Lazy(ll n, ll start, ll end)
{
	if (add_lazy[n] || sqrt_lazy[n])
	{
		if (sqrt_lazy[n])
		{
			segtree[n].sum = (sqrt_lazy[n] + add_lazy[n]) * (end - start + 1);
			segtree[n].mn = (sqrt_lazy[n] + add_lazy[n]);
			segtree[n].mx = (sqrt_lazy[n] + add_lazy[n]);
			if (start != end)
			{
				add_lazy[n * 2] = add_lazy[n];
				add_lazy[n * 2 + 1] = add_lazy[n];
				sqrt_lazy[n * 2] = sqrt_lazy[n];
				sqrt_lazy[n * 2 + 1] = sqrt_lazy[n];
			}
		}
		else
		{
			segtree[n].sum += add_lazy[n] * (end - start + 1);
			segtree[n].mn += add_lazy[n];
			segtree[n].mx += add_lazy[n];
			if (start != end)
			{
				add_lazy[n * 2] += add_lazy[n];
				add_lazy[n * 2 + 1] += add_lazy[n];
			}
		}
		add_lazy[n] = 0;
		sqrt_lazy[n] = 0;
	}
}

void Add(ll n, ll start, ll end, ll left, ll right, ll value)
{
	Lazy(n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		segtree[n].mx += value;
		segtree[n].mn += value;
		segtree[n].sum += value * (end - start + 1);
		if (start != end)
		{
			add_lazy[n * 2] += value;
			add_lazy[n * 2 + 1] += value;
		}
	}
	else
	{
		ll mid = (start + end) >> 1;
		Add(n * 2, start, mid, left, right, value);
		Add(n * 2 + 1, mid + 1, end, left, right, value);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void Sq(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		if (floor(sqrt(segtree[n].mn)) == floor(sqrt(segtree[n].mx)))
		{
			ll x = (ll)floor(sqrt(segtree[n].mx));
			segtree[n].sum = x * (end - start + 1);
			segtree[n].mx = x;
			segtree[n].mn = x;
			if (start != end)
			{
				sqrt_lazy[n * 2] = x;
				sqrt_lazy[n * 2 + 1] = x;
				add_lazy[n * 2] = 0;
				add_lazy[n * 2 + 1] = 0;
			}
			return;
		}
		else if (segtree[n].mn + 1 == segtree[n].mx)
		{
			ll x = (ll)(floor(sqrt(segtree[n].mn)) - segtree[n].mn);
			segtree[n].sum += x * (end - start + 1);
			segtree[n].mn += x;
			segtree[n].mx += x;
			if (start != end)
			{
				add_lazy[n * 2] += x;
				add_lazy[n * 2 + 1] += x;
			}
			return;
		}
	}
	ll mid = (start + end) >> 1;
	Sq(n * 2, start, mid, left, right);
	Sq(n * 2 + 1, mid + 1, end, left, right);
	segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].sum;
	ll mid = (start + end) >> 1;
	return get_sum(n * 2, start, mid, left, right) + get_sum(n * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	ll h = (ll)ceil(log2(N));
	segtree = vector<NODE>((1 << (h + 1)));
	add_lazy = vector<ll>((1 << (h + 1)), 0);
	sqrt_lazy = vector<ll>((1 << (h + 1)), 0);
	ary = vector<ll>(N);

	for (int i = 0; i < N; i++)
		cin >> ary[i];

	set_segtree(1, 0, N - 1);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> L >> R;

		if (ch == 1)
		{
			cin >> X;
			Add(1, 0, N - 1, L - 1, R - 1, X);
		}
		else if (ch == 2)
			Sq(1, 0, N - 1, L - 1, R - 1);
		else
			cout << get_sum(1, 0, N - 1, L - 1, R - 1) << '\n';
	}

	return 0;
}