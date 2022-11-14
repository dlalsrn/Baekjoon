#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1000000000
using namespace std;

vector <int> v;
vector <int> dp;
int N, mx = -inf;

int main(void)
{
	cin >> N;

	v = vector<int>(N + 1, 0);
	dp = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> v[i];

	for (int i = 1; i <= N; i++)
	{
		if (i != 1 && v[i] < 0)
			mx = max(mx, dp[i - 1]);
		if (dp[i - 1] > 0)
			dp[i] = v[i] + dp[i - 1];
		else
			dp[i] = v[i];
	}
	mx = max(mx, dp[N]);
	cout << mx;

	return 0;
}