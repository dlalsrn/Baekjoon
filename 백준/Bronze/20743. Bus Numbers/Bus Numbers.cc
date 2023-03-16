#include <iostream>
using namespace std;

long long N, a, b, cnt;

int main(void)
{
	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		cnt = 0;
		for (int a = 1; a * a * a <= N; a++)
			for (int b = 1; b * b * b <= N; b++)
				if (a * a * a + b * b * b == i)
					cnt++;
		if (cnt >= 4)
		{
			cout << i;
			return 0;
		}
	}
	cout << "none";
	return 0;
}