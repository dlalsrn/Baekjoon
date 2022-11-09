#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> ary;
vector <int> dp;
int N, mx = 0;

int main(void)
{
	cin >> N;

	ary = vector<int>(N);
	dp = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
		dp[i] = ary[i];
	}

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (ary[i] < ary[j])
				dp[j] = max(dp[j], dp[i] + ary[j]);

	for (int i = 0; i < N; i++)
		mx = max(mx, dp[i]);

	cout << mx;
	return 0;
}