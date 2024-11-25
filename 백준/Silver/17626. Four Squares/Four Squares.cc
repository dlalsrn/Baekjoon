#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> dp;

int main(void) {
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;

	dp = vector<int>(N + 1, 50001);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		int t = 1;
		while (t * t <= i) {
			dp[i] = min(dp[i], dp[i - t * t] + 1);
			t++;
		}
	}

	cout << dp[N];

	return 0;
}