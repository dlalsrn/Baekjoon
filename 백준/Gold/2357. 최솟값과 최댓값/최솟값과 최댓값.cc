// 최솟값
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

pair<ll, ll> min_max(pair<ll, ll> a, pair<ll, ll> b)
{
	ll min = a.first > b.first ? b.first : a.first;
	ll max = a.second < b.second ? b.second : a.second;
	return { min, max };
}

pair<ll, ll> segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
	{
		tree[n].first = node[start];
		tree[n].second = node[start];
		return tree[n];
	}
	else
		return tree[n] = min_max(segment(node, tree, n * 2, start, (start + end) / 2), segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end));;
}

pair<ll, ll> mn(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return {0, 0};
	if (left <= start && end <= right)
		return tree[n];
	pair<ll, ll> m1 = mn(tree, n * 2, start, (start + end) / 2, left, right);
	pair<ll, ll> m2 = mn(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (m1.first == 0)
		return m2;
	else if (m2.first == 0)
		return m1;
	else
		return min_max(m1, m2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b;
	cin >> N >> M;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];

	segment(node, segtree, 1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		pair<ll, ll> temp = mn(segtree, 1, 0, N - 1, a - 1, b - 1);
		cout << temp.first << ' ' << temp.second << '\n';
	}
}