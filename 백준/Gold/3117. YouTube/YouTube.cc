// YouTube
// 23.03.28
// sparse table
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, M, Q;
vector <int> v; // 처음보는 동영상
vector <int> c; // 추천하는 동영상
vector <vector<int>> dp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K >> M;
	M--;
	v.resize(N);
	c.resize(K);
	int h = floor(log2(M));

	dp = vector<vector<int>>(h + 1, vector<int>(K + 1));

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < K; i++)
		cin >> c[i];

	for (int i = 0; i < K; i++) // i+1번째 동영상에서 추천되는 동영상
		dp[0][i + 1] = c[i];

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= K; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];

	for (int i = 0; i < N; i++)
	{
		int x = v[i];
		for (int j = 0; j <= h; j++)
			if (M & (1 << j))
				x = dp[j][x];
		cout << x << ' ';
	}

	return 0;
}