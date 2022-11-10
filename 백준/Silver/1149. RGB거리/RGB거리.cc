#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> color;
vector <vector<int>> dp;
int N, mn = 1000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	color = vector<vector<int>>(N, vector<int>(3));
	dp = vector<vector<int>>(N, vector<int>(3));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> color[i][j];

	for (int i = 0; i < 3; i++)
		dp[0][i] = color[0][i];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}

	for (int i = 0; i < 3; i++)
		mn = min(mn, dp[N - 1][i]);

	cout << mn;

	return 0;
}