#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q, K, cnt = 0;
vector <int> v, ans;

int partition(int p, int r)
{
	int x = v[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (v[j] <= x)
		{
			cnt++;
			swap(v[j], v[++i]);
			if (cnt == K)
				ans = v;
		}
	}
	if (i + 1 != r)
	{
		cnt++;
		swap(v[i+1], v[r]);
		if (cnt == K)
			ans = v;
	}
	return i + 1;
}

int select(int p, int r, int q)
{
	if (p == r)
		return v[p];
	int t = partition(p, r);
	int k = t - p + 1;
	if (q < k)
		return select(p, t - 1, q);
	else if (q == k)
		return v[t];
	else
		return select(t + 1, r, q - k);
}

int main(void)
{
	cin >> N >> Q >> K;

	v = vector <int>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	select(1, N, Q);

	if (cnt < K)
		cout << -1;
	else
		for (int i = 1; i <= N; i++)
			cout << ans[i] << ' ';
	return 0;
}