// 23.09.07
// 세그먼트 트리
#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;
using ll = long long;

int N, K, x;
vector <ll> segtree[11];
vector <vector<ll>> dp;

void update(int n, int start, int end, int index, int k, int change)
{
	if (index < start || end < index)
		return;
	if (start == end)
		segtree[k][n] = (segtree[k][n] + change) % MOD;
	else
	{
		int mid = (start + end) >> 1;
		update(n * 2, start, mid, index, k, change);
		update(n * 2 + 1, mid + 1, end, index, k, change);
		segtree[k][n] = (segtree[k][n * 2] + segtree[k][n * 2 + 1]) % MOD;
	}
}

ll get_sum(int n, int start, int end, int left, int right, int k)
{
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return segtree[k][n];
	int mid = (start + end) >> 1;
	return (get_sum(n * 2, start, mid, left, right, k) + get_sum(n * 2 + 1, mid + 1, end, left, right, k)) % MOD;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;
	ll h = (ll)ceil(log2(N + 1));
	for (int i = 0; i < 11; i++)
		segtree[i] = vector<ll>((1 << (h + 1)), 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		for (int j = 0; j < 10; j++)
		{
			// 수열의 길이가 j인 1 ~ x-1 사이의 수 개수
			ll s = get_sum(1, 0, N, 1, x - 1, j);
			if (j != 0 && s == 0)
				break;
			if (j == 0)
				update(1, 0, N, x, j + 1, 1);
			else
				update(1, 0, N, x, j + 1, s);
		}
	}

	cout << get_sum(1, 0, N, 1, N, K) % MOD;

	return 0;
}