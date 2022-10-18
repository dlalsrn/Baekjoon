// 구간 곱 구하기
#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll segment(vector <ll>& node, vector <ll>& tree, ll n, ll start, ll end)
{
	if (start == end)
		return tree[n] = node[start];
	else
		return tree[n] = (segment(node, tree, n * 2, start, (start + end) / 2) * segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

ll update(vector <ll>& tree, ll n, ll index, ll start, ll end, ll change)
{
	if (index < start || end < index)
		return tree[n];
	if (start != end)
		return tree[n] = (update(tree, n * 2, index, start, (start + end) / 2, change) * update(tree, n * 2 + 1, index, (start + end) / 2 + 1, end, change)) % MOD;
	else
	{
		if (start == end && start == index)
			tree[n] = change;
		return tree[n];
	}
}
ll sum(vector<ll>& tree, ll n, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[n];
	return (sum(tree, n * 2, start, (start + end) / 2, left, right) * sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}

int main(void)
{
	int N, M, K;
	ll a, b, c, s;
	cin >> N >> M >> K;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <ll> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(segtree, 1, b - 1, 0, N - 1, c);
		else
		{
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << s << '\n';
		}
	}
}