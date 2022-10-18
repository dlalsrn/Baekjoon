// 수열과 쿼리 22
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
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
	map <pair<ll, pair<ll, ll>>, ll> m;
	queue <pair<ll, ll>> up;
	queue <pair<ll, pair<ll, ll>>> print;
	priority_queue <pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> query;
	int N, M;
	ll a, b, c, k, s, cnt, len;
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
			up.push({ b,c });
		}
		else
		{
			cin >> k >> b >> c;
			print.push({ k, {b, c} });
			query.push({ k, {b, c} });
		}
	}
	cnt = 0;
	pair <ll, pair<ll, ll>> temp;
	len = query.size();
	for (int i = 0; i < len; i++)
	{
		while(cnt != query.top().first)
		{
			update(segtree, 1, 0, N - 1, up.front().first - 1, up.front().second);
			up.pop();
			cnt++;
		}

		temp = { query.top().first, {query.top().second.first, query.top().second.second} };
		s = sum(segtree, 1, 0, N - 1, query.top().second.first - 1, query.top().second.second - 1);
		m[temp] = s;
		query.pop();
	}
	len = print.size();
	for (int i = 0; i < len; i++)
	{
		temp = { print.front().first, {print.front().second.first, print.front().second.second}};
		print.pop();
		cout << m[temp] << '\n';
	}
	return 0;
}