// 사탕상자
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

void segment(vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		tree[n] = 0;
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = 0;
	}
}

void update(vector <ll>& tree, ll n, ll start, ll end, ll taste, ll num)
{
	if (taste < start || end < taste)
		return;
	if (start != end)
	{
		update(tree, n * 2, start, (start + end) / 2, taste, num);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, taste, num);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
	else if (start == end && start == taste)
		tree[n] += num;
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
	{
		cout << start + 1 << '\n';
		update(tree, 1, 0, 999999, start, -1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	ll a, b, c;
	int h = (int)ceil(log2(1000000));
	vector <ll> segtree((1 << (h + 1)));
	segment(segtree, 1, 0, 999999);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 2)
		{
			cin >> b >> c;
			update(segtree, 1, 0, 999999, b - 1, c);
		}
		else
		{
			cin >> b;
			find(segtree, 1, 0, 999999, b);
		}
	}
}