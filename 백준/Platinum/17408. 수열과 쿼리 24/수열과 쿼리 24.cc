// 수열과 쿼리 24
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

pair<ll, ll> max(pair<ll, ll> a, pair<ll, ll> b, ll start, ll end)
{
	if (end - start == 1)
	{
		if (a.first == a.second)
		{
			if (b.first == b.second)
			{
				if (a.first > b.first)
					return { a.first, b.first };
				else
					return { b.first, a.first };
			}
			else
			{
				if (a.first > b.first)
					return { a.first, b.first };
				else
				{
					if (a.first > b.second)
						return { b.first, a.first };
					else
						return { b.first, b.second };
				}
			}
		}
		else
		{
			if (b.first == b.second)
			{
				if (a.first < b.first)
					return { b.first, a.first };
				else
				{
					if (a.second < b.first)
						return { a.first, b.first };
					else
						return { a.first, a.second };
				}
			}
			else
			{
				if (a.first > b.first)
				{
					if (a.second > b.first)
						return { a.first, a.second };
					else
						return { a.first, b.first };
				}
				else
				{
					if (a.first < b.second)
						return { b.first, b.second };
					else
						return { b.first, a.first };
				}
			}
		}
	}
	else
	{
		if (a.first == a.second)
		{
			if (b.first == b.second)
			{
				if (a.first > b.first)
					return { a.first, a.first };
				else
					return { b.first, b.first };
			}
			else
			{
				if (a.first > b.first)
					return { a.first, a.first };
				else
				{
					if (a.first > b.second)
						return { b.first, a.first };
					else
						return { b.first, b.second };
				}
			}
		}
		else
		{
			if (b.first == b.second)
			{
				if (a.first < b.first)
				{
					if (a.first < b.second)
						return { b.first, b.second };
					else
						return { b.first, a.first };
				}
				else
				{
					if (a.second < b.first)
						return { a.first, b.first };
					else
						return { a.first, a.second };
				}
			}
			else
			{
				if (a.first > b.first)
				{
					if (a.second > b.first)
						return { a.first, a.second };
					else
						return { a.first, b.first };
				}
				else
				{
					if (a.first < b.second)
						return { b.first, b.second };
					else
						return { b.first, a.first };
				}
			}
		}
	}
}

void segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { node[start], 0 };
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = max(tree[n * 2], tree[n * 2 + 1], start, end);
	}
}

void update(vector <pair<ll, ll>>& tree, ll n, ll start, ll end, ll index, ll change)
{
	if (index < start || end < index)
		return;
	if (start == end)
	{
		if (start == index)
		{
			tree[n].first = change;
			tree[n].second = 0;
		}
	}
	else
	{
		update(tree, n * 2, start, (start + end) / 2, index, change);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = max(tree[n * 2], tree[n * 2 + 1], start ,end);
	}
}

pair<ll, ll> mx(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return { 0, 0 };
	if (left <= start && end <= right)
		return tree[n];
	pair<ll, ll> m1 = mx(tree, n * 2, start, (start + end) / 2, left, right);
	pair<ll, ll> m2 = mx(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (m1.first == 0)
		return m2;
	else if (m2.first == 0)
		return m1;
	else
		return max(m1, m2, start, end);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	ll a, b, c;
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
			update(segtree, 1, 0, N - 1, b - 1, c);
		else
		{
			pair<ll, ll> t = mx(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << t.first + t.second << '\n';
		}
	}
}