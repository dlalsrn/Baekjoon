#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> v;
vector <vector<int>> dp;
int N, mx = 0;

int main(void)
{
	cin >> N;

	v = vector<vector<int>>(N);
	dp = vector<vector<int>>(N);
	
	for (int i = 0; i < N; i++)
	{
		v[i] = vector<int>(i + 1);
		dp[i] = vector<int>(i + 1, 0);
		for (int j = 0; j < i + 1; j++)
			cin >> v[i][j];
	}

	dp[0][0] = v[0][0];
	
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + v[i + 1][j + 1]);
		}
	}

	for (int i = 0; i < N; i++)
		mx = max(mx, dp[N - 1][i]);

	cout << mx;
	return 0;
}