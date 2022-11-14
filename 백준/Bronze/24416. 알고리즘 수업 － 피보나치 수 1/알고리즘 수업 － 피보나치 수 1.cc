#include <iostream>
using namespace std;
int N;

int main(void)
{
	cin >> N;
	int dp[40];
	dp[1] = dp[2] = 1;
	
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N] << ' ' << N - 2;

	return 0;
}