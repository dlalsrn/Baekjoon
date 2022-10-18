#include <iostream>
using namespace std;

int main(void)
{
	int N, M, min, sum = 0;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (j == i)
			{
				if (sum == 0)
					min = j;
				sum += j;
			}
			else if (i % j == 0)
				break;
		}
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << min;
	return 0;
}