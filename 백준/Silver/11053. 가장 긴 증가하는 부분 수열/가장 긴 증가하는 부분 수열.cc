#include <iostream>
using namespace std;

int main(void)
{
	int ary[1000];
	int DP[1000];
	int N, max = 1, n;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		ary[i] = n;
		DP[i] = 1;
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (ary[i] < ary[j] && DP[i] > DP[j] - 1)
			{
				DP[j]++;
				if (max < DP[j])
					max = DP[j];
			}
		}
	}
	cout << max;
	return 0;
}