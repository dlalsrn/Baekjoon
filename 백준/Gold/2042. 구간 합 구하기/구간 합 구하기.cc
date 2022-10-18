// 구간 합 구하기
// 세그먼트 트리
// 리프 노드의 개수가 N개이면 세그먼트 트리의 높이는 ceil(logN)+1
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