// 최솟값과 최댓값
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

void segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { node[start], node[start] };
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = min_max(tree[n * 2], tree[n * 2 + 1]);
	}
}

void update(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end, ll index, ll change)
{
	if (index > end || index < start)
		return;
	if (start == end)
	{
		if (start == index)
			tree[n] = { node[change], node[change] };
	}
	else
	{
		update(node, tree, n * 2, start, (start + end) / 2, index, change);
		update(node, tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = min_max(tree[n * 2], tree[n * 2 + 1]);
	}
}

pair<ll, ll> mn(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return {-1, -1};
	if (left <= start && end <= right)
		return tree[n];
	pair<ll, ll> m1 = mn(tree, n * 2, start, (start + end) / 2, left, right);
	pair<ll, ll> m2 = mn(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (m1.first == -1)
		return m2;
	else if (m2.first == -1)
		return m1;
	else
		return min_max(m1, m2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, T;
	ll a, b, c;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		cin >> N >> M;
		vector <ll> node(N);
		int h = (int)ceil(log2(N));
		vector <pair<ll, ll>> segtree((1 << (h + 1)));
		for (int i = 0; i < N; i++)
			node[i] = i;

		segment(node, segtree, 1, 0, N - 1);

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			if (a == 1)
			{
				pair<ll, ll> temp = mn(segtree, 1, 0, N - 1, b, c);
				if (temp.first == b && temp.second == c)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else
			{
				update(node, segtree, 1, 0, N - 1, b, c);
				update(node, segtree, 1, 0, N - 1, c, b);
				ll t = node[b];
				node[b] = node[c];
				node[c] = t;
			}
		}
	}
}