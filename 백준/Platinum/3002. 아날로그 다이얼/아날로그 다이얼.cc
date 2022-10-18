#include <iostream>
#include <vector>
#include <cmath>
#define MAX_digit 11
using namespace std;
typedef long long ll;
typedef struct
{
	ll sum;
	ll digit[MAX_digit];
}Node;

vector <Node> segtree;
vector <ll> lazy;
string value;

Node upt(Node a, Node b)
{
	Node c = { 0, 0 };
	c.sum = a.sum + b.sum;
	for (ll i = 0; i < MAX_digit; i++)
		c.digit[i] = a.digit[i] + b.digit[i];
	return c;
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
	{
		segtree[n].sum = value[start] - '0';
		segtree[n].digit[segtree[n].sum] = 1;
	}
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n] != 0)
	{
		ll t[MAX_digit] = { 0 };
		segtree[n].sum += lazy[n] * (end - start + 1);
		t[10] = (lazy[n] / 10) * (end - start + 1);
		lazy[n] %= 10;
		for (ll i = 0; i < MAX_digit - 1; i++)
		{
			if (i + lazy[n] >= 10)
				t[10] += segtree[n].digit[i];
			t[(i + lazy[n]) % 10] = segtree[n].digit[i];
		}
		for (ll i = 0; i < MAX_digit - 1; i++)
			segtree[n].digit[i] = t[i];
		segtree[n].digit[10] += t[10];
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		ll cnt = segtree[n].digit[9];
		segtree[n].sum += (end - start + 1);
		segtree[n].digit[10] += cnt;
		for (ll i = 9; i > 0; i--)
			segtree[n].digit[i] = segtree[n].digit[i - 1];
		segtree[n].digit[0] = cnt;
		if (start != end)
		{
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].sum - 10 * segtree[n].digit[10];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, l, r;
	cin >> N >> M;
	cin >> value;
	ll h = (ll)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)), { 0, 0 });
	lazy = vector<ll>((1 << (h + 1)));

	set_segtree(1, 0, N - 1);

	for (ll i = 0; i < M; i++)
	{
		cin >> l >> r;
		cout << get_sum(1, 0, N - 1, l - 1, r - 1) << '\n';
		update(1, 0, N - 1, l - 1, r - 1);
	}
	return 0;
}