// 나무 심기
#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;

void segment(vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { 0,0 };
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = { 0,0 };
	}
}

void update(vector <pair<ll, ll>>& tree, ll n, ll start, ll end, ll index)
{
	if (index < start || end < index)
		return;
	if (start != end)
	{
		update(tree, n * 2, start, (start + end) / 2, index);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index);
		tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
		tree[n].second = tree[n * 2].second + tree[n * 2 + 1].second;
	}
	else if (start == end && start == index)
	{
		tree[n].first += index;
		tree[n].second += 1;
	}
}

pair<ll, ll> sum(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return { 0, 0 };
	if (left <= start && end <= right)
		return tree[n];
	pair<ll, ll> p1 = sum(tree, n * 2, start, (start + end) / 2, left, right);
	pair<ll, ll> p2 = sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return { p1.first + p2.first, p1.second + p2.second };
}

int main(void)
{
	int N;
	ll s = 0;
	pair<ll, ll> left, right;
	cin >> N;;
	vector <ll> node(N);
	int h = (int)ceil(log2(200001));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(segtree, 1, 0, 200000);
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			update(segtree, 1, 0, 200000, node[i]);
		else
		{
			update(segtree, 1, 0, 200000, node[i]);
			left = sum(segtree, 1, 0, 200000, 0, node[i] - 1);
			right = sum(segtree, 1, 0, 200000, node[i] + 1, 200000);
			ll t = ((left.second * node[i] - left.first) + (right.first - right.second * node[i])) % MOD;
			if (s == 0)
				s = t;
			else
			{
				s = (s * t) % MOD;
			}
		}
	}
	cout << s;
	return 0;
}