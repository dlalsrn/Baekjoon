#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, D;
vector <ll> v;
vector <ll> dp;
deque <pair<ll, ll>> dq;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> D;

	v.resize(N);
	dp.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < N; i++)
	{
		dp[i] = v[i];

		// dq.front는 i번째까지 뛰었을 때의 최댓값
		while (!dq.empty() && dq.front().first < i - D)
			dq.pop_front();

		if (!dq.empty())
			dp[i] = max(dp[i], dq.front().second + dp[i]);

		// i까지 뛰었을 때가 앞의 인덱스들보다 크면 pop
		while (!dq.empty() && dq.back().second < dp[i])
			dq.pop_back();

		dq.push_back(make_pair(i, dp[i]));
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}