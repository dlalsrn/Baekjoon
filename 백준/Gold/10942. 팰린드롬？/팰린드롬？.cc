#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
vector <vector<int>> dp;
int N, M, l, r;
bool TF;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	v = vector<int>(N);
	dp = vector<vector<int>>(N, vector<int>(N, 1));

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < N; i++)
	{
		TF = true;
		for (int j = i + 1; j < N; j++)
		{
			if (v[j - 1] != v[j])
				TF = false;
			l = i, r = j;
			if (dp[i][j - 1] && !TF)
			{
				dp[i][j] = 0;
				continue;
			}
			if (dp[i][j - 1] && TF)
				continue;
			while (l <= r)
			{
				if (v[l] != v[r])
				{
					dp[i][j] = 0;
					break;
				}
				l++;
				r--;
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		cout << (dp[l - 1][r - 1] ? 1 : 0) << '\n';
	}

	return 0;
}