#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
vector <ll> segtree;
vector <pair<ll, ll>> value;
ll T, N, cnt;

void update(ll n, ll start, ll end, ll index)
{
	if (start == end)
		segtree[n] = 1;
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	cin >> T;

	for (ll t = 0; t < T; t++)
	{
		cin >> N;
		ll h = (ll)ceil(log2(N));

		segtree = vector<ll>((1 << (h + 1)), 0);
		value = vector<pair<ll, ll>>(N);

		for (ll i = 0; i < N; i++)
		{
			cin >> value[i].first;
			value[i].second = i;
		}

		sort(value.begin(), value.end());

		cnt = 0;
		for (ll i = 0; i < N; i++)
		{
			cnt += get_sum(1, 0, N - 1, value[i].second + 1, N - 1);
			update(1, 0, N - 1, value[i].second);
		}

		cout << cnt << '\n';
	}

	return 0;
}