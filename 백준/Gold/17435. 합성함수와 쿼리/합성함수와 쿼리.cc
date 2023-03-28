#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int M, Q, n, x;
vector <int> v;
vector <vector<int>> dp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;

	v.resize(M);
	int h = floor(log2(500000));

	dp = vector<vector<int>>(h + 1, vector<int>(M+1));

	for (int i = 0; i < M; i++)
		cin >> v[i];

	for (int i = 0; i < M; i++)
		dp[0][i+1] = v[i];
	
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= M; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> n >> x;
		for (int j = 0; j <= h; j++)
			if (n & (1 << j))
				x = dp[j][x];
		cout << x << '\n';
	}

	return 0;
}