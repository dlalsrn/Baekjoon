// 화려한 마을
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& node, vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = { node[start], 0 };
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = { 1, 0 };
	}
}

void lazy(vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (tree[n].second != 0)
	{
		tree[n].first = (1 << (tree[n].second - 1));
		if (start != end)
		{
			tree[n * 2].second = tree[n].second;
			tree[n * 2 + 1].second = tree[n].second;
		}
		tree[n].second = 0;
	}
}

void update(vector <pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right, ll change)
{
	lazy(tree, n, start, end);
	if (right < start || end < left)
		return;
	if (left <= start && end <= right)
	{
		tree[n].first = (1 << (change - 1));
		if (start != end)
		{
			tree[n * 2].second = change;
			tree[n * 2 + 1].second = change;
		}
		return;
	}
	update(tree, n * 2, start, (start + end) / 2, left, right, change);
	update(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
	tree[n].first = tree[n * 2].first | tree[n * 2 + 1].first;
}

ll sum(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	lazy(tree, n, start, end);
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n].first;
	return sum(tree, n * 2, start, (start + end) / 2, left, right) | sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, T, Q;
	string a;
	ll b, c, d, s, cnt;
	cin >> N >> T >> Q;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		node[i] = 1;
	segment(node, segtree, 1, 0, N - 1);
	for (int i = 0; i < Q; i++)
	{
		cin >> a;
		if (a == "C")
		{
			cin >> b >> c >> d;
			if (b > c)
			{
				ll temp = b;
				b = c;
				c = temp;
			}
			update(segtree, 1, 0, N - 1, b - 1, c - 1, d);
		}
		else
		{
			cnt = 0;
			cin >> b >> c;
			if (b > c)
			{
				ll temp = b;
				b = c;
				c = temp;
			}
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			while (s)
			{
				if (s % 2 == 1)
					cnt++;
				s /= 2;
			}
			cout << cnt << '\n';
		}
	}
}