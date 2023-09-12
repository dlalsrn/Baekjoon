#include <iostream>
using namespace std;

int N, M, K;

int main(void)
{
	cin >> N >> M >> K;

	cout << max(0, N - (M * K)) << ' ';
	if (N <= M)
		cout << N - 1;
	else if (N < M * K)
	{
		int t = 0;
		while (t + M <= N)
			t += M;
		cout << max(0, N - t - 1);
	}
	else
		cout << max(0, N - (M * K)) + (M - 1);

	return 0;
}