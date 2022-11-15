#include <iostream>
#include <vector>
using namespace std;

vector <int> dp;
int N;

int main(void)
{
	cin >> N;
	dp = vector<int>(N);
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	cout << dp[N - 1];
	return 0;
}