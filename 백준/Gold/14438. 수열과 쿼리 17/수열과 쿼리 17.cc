// 수열과 쿼리 17
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll min(ll a, ll b)
{
	return a > b ? b : a;
}

void segment(vector <ll>& node, vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = node[start];
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
	}
}

void update(vector <ll>& tree, ll n, ll start, ll end, ll index, ll change)
{
	if (index < start || end < index)
		return;
	if (start == end)
	{
		if (start == index)
			tree[n] = change;
	}
	else
	{
		update(tree, n * 2, start, (start+end)/2, index, change);
		update(tree, n * 2 + 1, (start+end)/2+1, end, index, change);
		tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
	}
}

ll mn(vector<ll>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n];
	ll m1 = mn(tree, n * 2, start, (start + end) / 2, left, right);
	ll m2 = mn(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (m1 == 0)
		return m2;
	else if (m2 == 0)
		return m1;
	else
		return min(m1, m2);
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
	vector <ll> segtree((1 << (h + 1)));
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
			cout << mn(segtree, 1, 0, N - 1, b - 1, c - 1) << '\n';
	}
}