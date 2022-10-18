#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector <ll> segtree;
vector <ll> node;
vector <pair<ll, ll>> lazy;
vector <bool> check;

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = node[start];
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = (segtree[n * 2] + segtree[n * 2 + 1]) % MOD;
	}
}

void Lazy(ll n, ll start, ll end)
{
	if (check[n])
	{
		segtree[n] = (lazy[n].second * (end - start + 1)) % MOD;
		if (start != end)
		{
			lazy[n * 2].second = lazy[n].second;
			lazy[n * 2 + 1].second = lazy[n].second;
			check[n * 2] = true;
			check[n * 2 + 1] = true;
		}
		lazy[n].first = 1;
		lazy[n].second = 0;
		check[n] = false;
	}
	else if (lazy[n].first != 1 || lazy[n].second != 0)
	{
		segtree[n] = (segtree[n] * lazy[n].first) % MOD;
		segtree[n] = (segtree[n] + lazy[n].second * (end - start + 1)) % MOD;
		if (start != end)
		{
			lazy[n * 2].first = (lazy[n * 2].first * lazy[n].first) % MOD;
			lazy[n * 2].second = (lazy[n * 2].second * lazy[n].first) % MOD;
			lazy[n * 2].second = (lazy[n * 2].second + lazy[n].second) % MOD;
			lazy[n * 2 + 1].first = (lazy[n * 2 + 1].first * lazy[n].first) % MOD;
			lazy[n * 2 + 1].second = (lazy[n * 2 + 1].second * lazy[n].first) % MOD;
			lazy[n * 2 + 1].second = (lazy[n * 2 + 1].second + lazy[n].second) % MOD;
		}
		lazy[n].first = 1;
		lazy[n].second = 0;
	}
}

void update(ll n, ll start, ll end, ll left, ll right, ll change, char op)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (op == '+')
		{
			segtree[n] = (segtree[n] + change * (end - start + 1)) % MOD;
			if (start != end)
			{
				lazy[n * 2].second = (lazy[n * 2].second + change) % MOD;
				lazy[n * 2 + 1].second = (lazy[n * 2 + 1].second + change) % MOD;
			}
		}
		else if (op == '*')
		{
			segtree[n] = (segtree[n] * change) % MOD;
			if (start != end)
			{
				lazy[n * 2].first = (lazy[n * 2].first * change) % MOD;
				lazy[n * 2].second = (lazy[n * 2].second * change) % MOD;
				lazy[n * 2 + 1].first = (lazy[n * 2 + 1].first * change) % MOD;
				lazy[n * 2 + 1].second = (lazy[n * 2 + 1].second * change) % MOD;
			}
		}
		else if (op == '=')
		{
			segtree[n] = (change * (end - start + 1)) % MOD;
			if (start != end)
			{
				lazy[n * 2].first = 1;
				lazy[n * 2].second = change;
				check[n * 2] = true;
				lazy[n * 2 + 1].first = 1;
				lazy[n * 2 + 1].second = change;
				check[n * 2 + 1] = true;
			}
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change, op);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, op);
		segtree[n] = (segtree[n * 2] + segtree[n * 2 + 1]) % MOD;
	}
}

ll sum(ll n, ll start, ll end, ll left, ll right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n] % MOD;
	return (sum(n * 2, start, (start + end) / 2, left, right) + sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, ch, x, y, v;
	char op;
	cin >> N;
	ll h = (ll)ceil(log2(N));
	segtree = vector<ll>((1 << (h + 1)));
	node = vector<ll>(N);
	lazy = vector<pair<ll, ll>>((1 << (h + 1)), {1, 0});
	check = vector<bool>((1 << (h + 1)), false);

	for (ll i = 0; i < N; i++)
		cin >> node[i];

	set_segtree(1, 0, N - 1);
	cin >> M;

	for (ll i = 0; i < M; i++)
	{
		cin >> ch >> x >> y;
		if (ch == 4)
			cout << sum(1, 0, N - 1, x - 1, y - 1) % MOD << '\n';
		else
		{
			cin >> v;
			if (ch == 1)
				op = '+';
			else if (ch == 2)
				op = '*';
			else
				op = '=';
			update(1, 0, N - 1, x - 1, y - 1, v, op);
		}
	}
	return 0;
}