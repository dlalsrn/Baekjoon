#include <bits/stdc++.h>
using namespace std;

int N, K, x, ans = 0;
vector <int> v, diff;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	v.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		diff.push_back(v[i + 1] - v[i]);
		ans += v[i + 1] - v[i];
	}

	sort(diff.begin(), diff.end(), greater<>());

	for (int i = 0; i < K; i++) ans -= diff[i];

	cout << ans;

	return 0;
}
