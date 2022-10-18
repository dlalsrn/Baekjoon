#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (b - a == 0)
			cout << b << '\n';
		else if (b - a == 1)
			cout << (a ^ b) << '\n';
		else
		{
			if (a % 2 == 0)
			{
				sum = a ^ (a+1);
				a += 1;
			}
			else
			{
				sum = a ^ (a + 1) ^ (a + 2);
				a += 2;
			}
			int len = (b - a) % 4;
			for (int j = 0; j < len; j++)
			{
				sum ^= b--;
			}
			cout << sum << '\n';
		}
	}
	return 0;
}