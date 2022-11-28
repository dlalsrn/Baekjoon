#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> dp;
int N, K, MX = 0;
pair<int, int> mx, smax, pre_mx = { 0, -1 }, pre_smax;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;

	dp.resize(K, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		mx = { 0, -1 };
		
		for (int k = 0; k < K; k++)
		{
			cin >> dp[k][i];
			dp[k][i] += (pre_mx.second != k ? pre_mx.first : pre_smax.first);
			
			if (mx.first <= dp[k][i])
			{
				smax = mx;
				mx = { dp[k][i], k };
			}
			else if (smax.first < dp[k][i])
				smax = { dp[k][i], k };
		}
		pre_mx = mx;
		pre_smax = smax;
	}

	for (int k = 0; k < K; k++)
		MX = max(MX, dp[k][N - 1]);

	cout << MX;
	return 0;
}