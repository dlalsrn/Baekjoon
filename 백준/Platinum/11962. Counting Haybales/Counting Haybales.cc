#include <iostream>
#include <vector>
#include <cmath>
#define MAX 10000000001
using namespace std;
typedef long long ll;
typedef struct
{
	ll SUM;
	ll MIN;
}Node;

vector <Node> segtree;
vector <ll> lazy;
vector <ll> value;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n] != 0)
	{
		segtree[n].SUM += lazy[n] * (end - start + 1);
		segtree[n].MIN += lazy[n];
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { value[start], value[start] };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = { segtree[n * 2].SUM + segtree[n * 2 + 1].SUM, min(segtree[n * 2].MIN, segtree[n * 2 + 1].MIN) };
	}
}	

void update(ll n, ll start, ll end, ll left, ll right, ll change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		segtree[n].SUM += change * (end - start + 1);
		segtree[n].MIN += change;
		if (start != end)
		{
			lazy[n * 2] += change;
			lazy[n * 2 + 1] += change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = { segtree[n * 2].SUM + segtree[n * 2 + 1].SUM, min(segtree[n * 2].MIN, segtree[n * 2 + 1].MIN) };
	}
}

ll get_min(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return MAX;
	if (left <= start && end <= right)
		return segtree[n].MIN;
	return min(get_min(n * 2, start, (start + end) / 2, left, right), get_min(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].SUM;
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, l, r, c;
	char ch;
	cin >> N >> M;
	ll h = (ll)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)));
	lazy = vector<ll>((1 << (h + 1)));
	value = vector<ll>(N);

	for (int i = 0; i < N; i++)
		cin >> value[i];

	set_segtree(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> l >> r;
		if (ch == 'M')
			cout << get_min(1, 0, N - 1, l - 1, r - 1) << '\n';
		else if (ch == 'S')
			cout << get_sum(1, 0, N - 1, l - 1, r - 1) << '\n';
		else
		{
			cin >> c;
			update(1, 0, N - 1, l - 1, r - 1, c);
		}
	}
	return 0;
}