#include <iostream>
#include <vector>
#include <map>
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
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

void update(vector <ll>& tree, ll n, ll start, ll end, ll index, ll change)
{
	if (index < start || end < index)
		return;
	if (start != end)
	{
		update(tree, n * 2, start, (start + end) / 2, index, change);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
	else if (start == end && start == index)
		tree[n] = change;
}

ll sum(vector<ll>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n];
	return sum(tree, n * 2, start, (start + end) / 2, left, right) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	ll total = 0, num;
	cin >> N;
	vector <ll> node(N);
	vector <ll> v(1000001);
	int h = (int)ceil(log2(N));
	vector <ll> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[num] = i;
	}
	segment(segtree, 1, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		num = sum(segtree, 1, 0, N - 1, v[node[i]]+1, N - 1);
		total += num;
		update(segtree, 1, 0, N - 1, v[node[i]], 1);
	}
	cout << total;
	return 0;
}