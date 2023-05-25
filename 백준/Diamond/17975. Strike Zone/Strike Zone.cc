#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> pii;
typedef struct
{
	ll L_MAX;
	ll R_MAX;
	ll T_MAX;
	ll ALL;
}NODE;

vector <pii> gold;
vector <ll> X;
vector <ll> Y;
vector <NODE> segtree;
vector <pair<ll, ll>> x1_point;
vector <pair<ll, ll>> x2_point;
ll N1, N2, x, y, c1, c2, mx;

NODE upt(NODE LEFT, NODE RIGHT)
{
	NODE t;
	t.L_MAX = max(LEFT.L_MAX, LEFT.ALL + RIGHT.L_MAX);
	t.R_MAX = max(RIGHT.R_MAX, RIGHT.ALL + LEFT.R_MAX);
	t.T_MAX = max(LEFT.T_MAX, max(RIGHT.T_MAX, LEFT.R_MAX + RIGHT.L_MAX));
	t.ALL = LEFT.ALL + RIGHT.ALL;
	return t;
}

void update(ll n, ll start, ll end, ll index, ll change)
{
	if (start == end)
	{
		segtree[n].L_MAX += change;
		segtree[n].R_MAX += change;
		segtree[n].T_MAX += change;
		segtree[n].ALL += change;
	}
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N1;
	for (ll i = 0; i < N1; i++)
	{
		cin >> x >> y;
		x1_point.push_back(make_pair(y, x));
		X.push_back(x);
		Y.push_back(y);
	}

	cin >> N2;
	for (ll i = 0; i < N2; i++)
	{
		cin >> x >> y;
		x2_point.push_back(make_pair(y, x));
		X.push_back(x);
		Y.push_back(y);
	}

	cin >> c1 >> c2;

	for (ll i = 0; i < N1; i++)
	{
		x = x1_point[i].second;
		y = x1_point[i].first;
		gold.push_back(make_pair(y, make_pair(x, c1)));
	}
	for (ll i = 0; i < N2; i++)
	{
		x = x2_point[i].second;
		y = x2_point[i].first;
		gold.push_back(make_pair(y, make_pair(x, -c2)));
	}

	sort(gold.begin(), gold.end());
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	ll h = (ll)ceil(log2(X.size()));

	for (ll y = 0; y < Y.size(); y++)
	{
		segtree = vector<NODE>((1 << (h + 1)), { 0, 0, 0, 0 });
		for (ll i = 0; i < N1 + N2; i++)
		{
			if (gold[i].first < Y[y])
				continue;
			update(1, 0, X.size() - 1, lower_bound(X.begin(), X.end(), gold[i].second.first) - X.begin(), gold[i].second.second);
			if (i < (N1 + N2) - 1 && gold[i].first == gold[i + 1].first)
				continue;
			mx = max(mx, segtree[1].T_MAX);
		}
	}

	cout << mx;

	return 0;
}