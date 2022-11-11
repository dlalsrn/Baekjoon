#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
vector <int> dp;
int N;

int main(void)
{
	cin >> N;

	v = vector<int>(N, 0);
	dp = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[1] + v[2], v[0] + v[2]);
	for (int i = 3; i < N; i++)
		dp[i] = max(v[i] + v[i - 1] + dp[i - 3], v[i] + dp[i - 2]);

	cout << dp[N - 1];

	return 0;
}