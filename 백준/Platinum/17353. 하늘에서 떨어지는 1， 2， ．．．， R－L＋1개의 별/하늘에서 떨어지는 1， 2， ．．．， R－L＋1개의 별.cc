#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector <ll> segtree;
vector<pair<ll, ll>> lazy;
vector <ll> star;

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = star[start];
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void Lazy(ll n, ll start, ll end)
{
	if (lazy[n].first != 0)
	{
		if (start != end)
		{
			//cout << n << " 좌 : " << (lazy[n].first - (lazy[n].second*(end - (start+end)/2))) << " 우 : " << lazy[n].first << '\n';
			lazy[n * 2].first += (lazy[n].first - (lazy[n].second * (end - (start + end) / 2)));
			lazy[n * 2 + 1].first += lazy[n].first;
			lazy[n * 2].second += lazy[n].second;
			lazy[n * 2 + 1].second += lazy[n].second;
		}
		else
			segtree[n] += lazy[n].first;
		lazy[n].first = 0;
		lazy[n].second = 0;
	}
}

void update(ll n, ll start, ll end, ll left, ll right, ll change, ll R)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			//cout << n << " 좌 : " << change - (R - (start + end) / 2) << " 우 : " << change << '\n';
			lazy[n * 2].first += (change - (R - (start + end) / 2));
			lazy[n * 2 + 1].first += change;
			lazy[n * 2].second++;
			lazy[n * 2 + 1].second++;
		}
		else
			segtree[n] += change;
	}
	else
	{
		if (right <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, left, right, change, R);
		else if (left >= (start + end) / 2 + 1)
			update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, R);
		else
		{
			//cout << n << " 좌 : " << change - (R - (start + end) / 2) << " 우 : " << change << '\n';
			update(n * 2, start, (start + end) / 2, left, right, change - (R - (start + end) / 2), (start+end)/2);
			update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, R);
		}
	}
}

ll find(ll n, ll start, ll end, ll index)
{
	Lazy(n, start, end);
	if (index < start || index > end)
		return 0;
	if (start == end && start == index)
		return segtree[n];
	return find(n * 2, start, (start + end) / 2, index) + find(n * 2 + 1, (start + end) / 2 + 1, end, index);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, X, L, R, ch;
	cin >> N;
	ll h = (ll)ceil(log2(N));
	segtree = vector<ll>((1 << (h + 1)));
	lazy = vector<pair<ll, ll>>((1 << (h + 1)), { 0,0 });
	star = vector<ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> star[i];

	set_segtree(1, 0, N - 1);

	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		cin >> ch;
		if (ch == 1)
		{
			cin >> L >> R;
			update(1, 0, N - 1, L - 1, R - 1, R - L + 1, R - 1);
		}
		else
		{
			cin >> X;
			cout << find(1, 0, N - 1, X - 1) << '\n';
		}
	}
	return 0;
}