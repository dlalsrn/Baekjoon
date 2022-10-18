// 음주 코딩
#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
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
		tree[n] = (tree[n * 2] * tree[n * 2 + 1]) % MOD;
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
		update(tree, n * 2, start, (start + end) / 2, index, change);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = (tree[n * 2] * tree[n * 2 + 1]) % MOD;
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	string a;
	ll b, c, s;

	while (cin >> N >> M)
	{
		vector <ll> node(N);
		int h = (int)ceil(log2(N));
		vector <ll> segtree((1 << (h + 1)));
		for (int i = 0; i < N; i++)
			cin >> node[i];
		segment(node, segtree, 1, 0, N - 1);
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			if (a == "C")
				update(segtree, 1, 0, N - 1, b - 1, c);
			else
			{
				s = sum(segtree, 1, 0, N - 1, b - 1, c - 1);
				if (s > 0)
					cout << '+';
				else if (s < 0)
					cout << '-';
				else
					cout << 0;
			}
		}
		cout << '\n';
	}
}