#include "videoclips.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <vector<int>> dp;
int global_M, h;

void videos(int K, int M, int S[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	global_M = --M;
	h = floor(log2(M));
	dp = vector<vector<int>>(h + 1, vector<int>(K));

	for (int i = 0; i < K; i++)
		dp[0][i] = S[i];

	for (int i = 1; i <= h; i++)
		for (int j = 0; j < K; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
}

int clip(int I) {
	for (int j = 0; j <= h; j++)
		if (global_M & (1 << j))
			I = dp[j][I];
	return I;
}