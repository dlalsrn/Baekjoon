// 수열과 쿼리 37
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
	{
		if (node[start] % 2 == 0)
			tree[n] = { 0, 1 };
		else
			tree[n] = { 1, 0 };
	}
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
		tree[n].second = tree[n * 2].second + tree[n * 2 + 1].second;
	}
}

void update(vector <pair<ll, ll>>& tree, ll n, ll index, ll start, ll end, ll change)
{
	if (index < start || end < index)
		return;
	if (start != end)
	{
		update(tree, n * 2, index, start, (start + end) / 2, change);
		update(tree, n * 2 + 1, index, (start + end) / 2 + 1, end, change);
		tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
		tree[n].second = tree[n * 2].second + tree[n * 2 + 1].second;
	}
	else if (start == end && start == index)
	{
		if (change % 2 == 0)
			tree[n] = { 0, 1 };
		else
			tree[n] = { 1, 0 };
	}
}

pair<ll, ll> sum(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return { 0, 0 };
	if (left <= start && end <= right)
		return tree[n];
	pair<ll, ll> s1 = sum(tree, n * 2, start, (start + end) / 2, left, right);
	pair<ll, ll> s2 = sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return { s1.first + s2.first, s1.second + s2.second };
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c;
	pair<ll, ll> s;
	cin >> N;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(segtree, 1, b - 1, 0, N - 1, c);
		else if (a == 2)
		{
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << s.second << '\n';
		}
		else if (a == 3)
		{
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << s.first << '\n';
		}
	}
}