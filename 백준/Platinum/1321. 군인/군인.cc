// 군인
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& node, vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = node[start];
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

void update(vector <ll>& tree, ll n, ll index, ll start, ll end, ll change)
{
	if (index < start || end < index)
		return;
	if (start != end)
	{
		update(tree, n * 2, index, start, (start + end) / 2, change);
		update(tree, n * 2 + 1, index, (start + end) / 2 + 1, end, change);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
	else if (start == end && start == index)
		tree[n] += change;
}

void find(vector<ll>& tree, ll n, ll start, ll end, ll num)
{
	if (start != end)
	{
		if (tree[n * 2] >= num)
			find(tree, n * 2, start, (start + end) / 2, num);
		else
		{
			num -= tree[n * 2];
			find(tree, n * 2 + 1, (start + end) / 2 + 1, end, num);
		}
	}
	else
		cout << start + 1 << '\n';
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
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			update(segtree, 1, b - 1, 0, N - 1, c);
		}
		else
		{
			cin >> b;
			find(segtree, 1, 0, N - 1, b);
		}
	}
}