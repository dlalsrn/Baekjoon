#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
vector <int> dp;
int N, mx = -1000000000;

int main(void)
{
	cin >> N;

	v = vector<int>(N, 0);
	dp = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	dp[0] = v[0];
	for (int i = 1; i < N; i++)
		dp[i] = max(v[i], v[i] + dp[i - 1]);

	for (int i = 0; i < N; i++)
		mx = max(mx, dp[i]);
	cout << mx;

	return 0;
}