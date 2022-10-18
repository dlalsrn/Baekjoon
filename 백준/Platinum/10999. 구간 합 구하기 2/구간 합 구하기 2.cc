// 구간 합 구하기 2
// lazy 세그먼트 트리
// 갱신 값이 들어오면 리프노드까지 갱신해주지 말고 해당 노드의 범위가 갱신 범위에 들어오면 일단 그 노드만 갱신
// 자식은 갱신했다 '치고' 갱신할 값을 자식한테 lazy 값으로 넘겨줌
// 그 다음 실행 때 lazy값을 가진 노드를 만나면 lazy값 만큼 노드 값 갱신
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
		tree[n] = { tree[n * 2].first + tree[n * 2 + 1].first, 0 };
	}
}

void lazy(vector <pair<ll, ll>>& tree, ll n, ll start, ll end)
{
	if (tree[n].second != 0)
	{
		tree[n].first += (end - start + 1) * tree[n].second;
		if (start != end)
		{
			tree[n * 2].second += tree[n].second;
			tree[n * 2 + 1].second += tree[n].second;
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
		tree[n].first += change * (end - start + 1);
		if (start != end)
		{
			tree[n * 2].second += change;
			tree[n * 2 + 1].second += change;
		}
		return;
	}
	update(tree, n * 2, start, (start + end) / 2, left, right, change);
	update(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
	tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
}

ll sum(vector<pair<ll, ll>>& tree, ll n, ll start, ll end, ll left, ll right)
{
	lazy(tree, n, start, end);
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[n].first;
	return sum(tree, n * 2, start, (start + end) / 2, left, right) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	int N, M, K;
	ll a, b, c, d, s;
	cin >> N >> M >> K;
	vector <ll> node(N);
	int h = (int)ceil(log2(N));
	vector <pair<ll, ll>> segtree((1 << (h + 1)));
	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(segtree, 1, 0, N - 1, b - 1, c - 1, d);
		}
		else
		{
			cin >> b >> c;
			s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
			cout << s << '\n';
		}
	}
}