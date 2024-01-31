#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N;
vector <pi> v;
vector <int> ary, dp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N);
	ary.resize(N);
	dp.resize(N, 1);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		ary[i] = v[i].second;

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (ary[i] < ary[j]) dp[j] = max(dp[j], dp[i] + 1);

	cout << N - *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}