#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

typedef struct
{
	ll mx; ll index; ll L_MAX; ll R_MAX; ll T_MAX; ll ALL;
}NODE;

vector <NODE> segtree;
vector <ll> value;
ll N, Q, ch, a, b, x;

NODE upt(NODE Left, NODE Right)
{
	NODE t;

	if (Left.L_MAX == 0) t.L_MAX = (ll)0;
	else if (Left.ALL == Left.L_MAX && Left.L_MAX == Left.R_MAX) t.L_MAX = Left.R_MAX + Right.L_MAX;
	else t.L_MAX = Left.L_MAX;

	if (Right.R_MAX == 0) t.R_MAX = (ll)0;
	else if (Right.ALL == Right.L_MAX && Right.L_MAX == Right.R_MAX) t.R_MAX = Right.L_MAX + Left.R_MAX;
	else t.R_MAX = Right.R_MAX;

	t.T_MAX = max({ Left.T_MAX, Right.T_MAX, Left.R_MAX + Right.L_MAX });
	t.ALL = Left.ALL + Right.ALL;

	if (Left.mx < Right.mx)
	{
		t.mx = Right.mx;
		t.index = Right.index;
	}
	else
	{
		t.mx = Left.mx;
		t.index = Left.index;
	}
	return t;
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { value[start], start, value[start], value[start], value[start] , value[start] };
	else
	{
		ll mid = (start + end) >> 1;
		set_segtree(n * 2, start, mid);
		set_segtree(n * 2 + 1, mid + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void update(ll n, ll start, ll end, ll index, ll v)
{
	if (start == end)
	{
		ll t = segtree[n].mx + v;
		segtree[n] = { t, start, t, t, t, t };
	}
	else
	{
		ll mid = (start + end) >> 1;
		if (index <= mid) update(n * 2, start, mid, index, v);
		else update(n * 2 + 1, mid + 1, end, index, v);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

pl get_max(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end) return make_pair(0, 0);
	if (left <= start && end <= right) return make_pair(segtree[n].mx, segtree[n].index);
	ll mid = (start + end) >> 1;
	pl L = get_max(n * 2, start, mid, left, right);
	pl R = get_max(n * 2 + 1, mid + 1, end, left, right);
	return (L.first < R.first ? R : L);
}

NODE get_sum(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end) return { (ll)0 };
	if (left <= start && end <= right) return segtree[n];
	ll mid = (start + end) >> 1;
	return upt(get_sum(n * 2, start, mid, left, right), get_sum(n * 2 + 1, mid + 1, end, left, right));
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	ll h = (ll)ceil(log2(N));
	segtree = vector<NODE>((1 << (h + 1)));
	value = vector<ll>(N);

	for (int i = 0; i < N; i++) cin >> value[i];

	set_segtree(1, 0, N - 1);

	for (int i = 0; i < Q; i++)
	{
		cin >> ch >> a >> b;

		if (ch == 1)
		{
			a--;
			while (b)
			{
				ll v = min(value[a], b);
				b -= v;
				value[a] -= v;
				update(1, 0, N - 1, a, -v);
				pl next = get_max(1, 0, N - 1, a + 1, N - 1);
				if (next.first <= 0) break;
				a = next.second;
			}
		}
		else if (ch == 2)
		{
			value[a - 1] += b;
			update(1, 0, N - 1, a - 1, b);
		}
		else cout << get_sum(1, 0, N - 1, a - 1, b - 1).T_MAX << '\n';
	}

	return 0;
}
