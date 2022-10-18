#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define inf 1000000000
using namespace std;
typedef long long ll;
typedef struct
{
	ll MIN;
	ll MAX;
	ll TOTAL;
}NODE;

vector <NODE> segtree;
vector <ll> value;
ll N, M, l, r, ch;

NODE upt(NODE L, NODE R)
{
	NODE T;
	T.TOTAL = max({ L.TOTAL, R.TOTAL, R.MAX - L.MIN });
	T.MAX = max(L.MAX, R.MAX);
	T.MIN = min(L.MIN, R.MIN);
	return T;
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { value[start], value[start], 0 };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void update(ll n, ll start, ll end, ll index, ll change)
{
	if (start == end)
		segtree[n] = { change, change, 0 };
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

NODE get_max(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return { inf, -inf, 0 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	ll h = (ll)ceil(log2(N));
	segtree = vector<NODE>((1 << (h + 1)));
	value = vector<ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> value[i];

	set_segtree(1, 0, N - 1);

	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		cin >> ch >> l >> r;
		if (ch == 1)
			update(1, 0, N - 1, l - 1, r);
		else
			cout << get_max(1, 0, N - 1, l - 1, r - 1).TOTAL << '\n';
	}
}