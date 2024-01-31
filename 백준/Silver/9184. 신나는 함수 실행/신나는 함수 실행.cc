#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int dp[21][21][21];

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);


	for (int a = 0; a < 21; a++)
		for (int b = 0; b < 21; b++)
			for (int c = 0; c < 21; c++)
				dp[a][b][c] = 1;

	for (int a = 1; a < 21; a++)
	{
		for (int b = 1; b < 21; b++)
		{
			for (int c = 1; c < 21; c++)
			{
				if (a < b && b < c)
					dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
				else
					dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
			}
		}
	}
	while (true)
	{
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= 0 || b <= 0 || c <= 0)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << '\n';
		else if (a > 20 || b > 20 || c > 20)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[20][20][20] << '\n';
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a][b][c] << '\n';
	}

	return 0;
}
