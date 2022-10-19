#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

vector <ll> X;
vector <ll> Y;
vector <pair<ll, ll>> poll;
vector <ll> segtree;
ll T, N, x, y;

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second < b.second;
}
void update(ll n, ll start, ll end, ll index)
{
	if (start == end)
		segtree[n]++;
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;

	for (ll t = 0; t < T; t++)
	{
		cin >> N;

		X = vector<ll>();
		Y = vector<ll>();
		poll = vector<pair<ll, ll>>();

		for (ll i = 0; i < N; i++)
		{
			cin >> x >> y;
			X.push_back(x);
			Y.push_back(y);
			poll.push_back(make_pair(x, y));
		}

		sort(poll.begin(), poll.end(), compare);
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());

		ll h = (ll)ceil(log2(X.size()));
		segtree = vector<ll>((1 << (h + 1)), 0);

		ll sum = 0;
		for (ll i = 0; i < N; i++)
		{
			x = poll[i].first;
			ll id = lower_bound(X.begin(), X.end(), x) - X.begin();
			sum += get_sum(1, 0, X.size() - 1, id, X.size() - 1);
			update(1, 0, X.size() - 1, id);
		}
		cout << sum << '\n';
	}

	return 0;
}