#include <iostream>
using namespace std;

int main(void)
{
	int T, n;
	bool TF[10001] = { 0 };
	TF[1] = true;
	for (int i = 2; i * i <= 10000; i++)
	{
		if (!TF[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				if (!TF[j])
					TF[j] = true;
			}
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int k = n/2; k >= 2; k--)
		{
			if (!TF[k])
			{
				if (!TF[n - k])
				{
					cout << k << ' ' << n - k << '\n';
					break;
				}
			}
		}
	}
	return 0;
}