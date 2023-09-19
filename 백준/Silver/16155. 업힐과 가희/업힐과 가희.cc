#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, X, Y, s, e, start, finish, g, a, b = 1, c, d = 1, t;

vector<pair<ll, ll>> v;
vector <ll> point;

ll gcd(ll x, ll y)
{
	while (y)
	{
		ll t = x % y;;
		x = y;
		y = t;
	}
	return x;
}

int main(void)
{
	cin >> N;

	for (ll i = 0; i < N + 1; i++)
	{
		cin >> X >> Y;
		v.push_back(make_pair(X, i));
		point.push_back(Y);
	}

	sort(v.begin(), v.end());
	cin >> start >> finish;

	s = lower_bound(v.begin(), v.end(), make_pair(start, (ll)0)) - v.begin();
	a = point[s];
	if (v[s].first != start)
	{
		t = lower_bound(v.begin(), v.end(), make_pair(start, (ll)0)) - v.begin();
		a = (point[v[t].second] - point[v[s - 1].second]) * (start - v[s - 1].first);
		b = v[t].first - v[s - 1].first;
		a += b * point[v[s - 1].second];
	}

	e = lower_bound(v.begin(), v.end(), make_pair(finish, (ll)0)) - v.begin();
	c = point[e];
	if (v[e].first != finish)
	{
		t = lower_bound(v.begin(), v.end(), make_pair(finish, (ll)0)) - v.begin();
		c = (point[v[t].second] - point[v[e - 1].second]) * (finish - v[e - 1].first);
		d = v[t].first - v[e - 1].first;
		c += d * point[v[e - 1].second];
	}

	X = finish - start;
	Y = c * b - a * d;
	t = d * b;
	X *= t;
	ll a = X;
	ll b = Y;
	if (a < b)
		swap(a, b);

	g = gcd(a, b);
	
	Y = abs(Y / g);
	X = abs(X / g);

	if (Y % X)
		cout << Y << '/' << X;
	else
		cout << Y / X;

	return 0;
}