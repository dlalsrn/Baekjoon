#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = 1'000'000'007;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;

    for (int i = 0; i < puddles.size(); ++i)
    {
        int y = puddles[i][1];
        int x = puddles[i][0];
        dp[y][x] = -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i == 1 && j == 1) || dp[i][j] == -1)
            {
                continue;
            }

            int up = max(0, dp[i - 1][j]);
            int left = max(0, dp[i][j - 1]);

            dp[i][j] = max(dp[i][j], up + left) % MAX;
        }
    }

    return dp[n][m];
}