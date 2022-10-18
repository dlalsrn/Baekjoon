#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector <ll> segtree;
vector <vector<ll>> node;
ll T, N, M, K, cnt, n1, n2, h;

void update(ll n, ll start, ll end, ll index)
{
	if (start == end)
		segtree[n]++;
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cnt = 0;
		cin >> N >> M >> K;
		h = (ll)ceil(log2(M));
		segtree = vector<ll>((1 << (h + 1)), 0);
		node = vector<vector<ll>>(N + 1);
		for (int i = 0; i < K; i++)
		{
			cin >> n1 >> n2;
			node[n1].push_back(n2);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int x : node[i])
				cnt += get_sum(1, 0, M - 1, x, M - 1);
			for (int x : node[i])
				update(1, 0, M - 1, x - 1);
		}
		cout << "Test case " << t << ": " << cnt << '\n';
	}

	return 0;
}