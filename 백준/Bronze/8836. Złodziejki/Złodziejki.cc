#include <iostream>
using namespace std;

int T, N, K;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;
		if (N <= K)
			cout << K - N << '\n';
		else
		{
			while (N > K)
				N -= (K - 1);
			cout << K - N << '\n';
		}
	}

	return 0;
}