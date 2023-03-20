#include <iostream>
#include <vector>
using namespace std;

int N, K, ans = 0;
vector<int> v;

void solve(int i, int sum, int c)
{
	if (sum >= K)
	{
		c += sum - K;
		sum = 0;
		ans = max(ans, c);
	}
	if (i < N)
	{
		if (sum == 0)
		{
			solve(i + 1, 0, c);
			solve(i + 1, sum + v[i], c);
		}
		else
			solve(i + 1, sum + v[i], c);
	}
}

int main(void)
{
	cin >> N >> K;

	v = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	solve(0, 0, 0);

	cout << ans;

	return 0;
}