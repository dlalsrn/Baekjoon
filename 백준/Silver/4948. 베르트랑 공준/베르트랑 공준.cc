#include <iostream>
using namespace std;

int main(void)
{
	bool TF[246913] = { 0 };
	TF[1] = true;
	int n = 123456, cnt;
	for (int i = 2; i * i <= 2 * n; i++)
	{
		if (!TF[i])
		{
			for (int j = i * i; j <= 2 * n; j += i)
			{
				if (!TF[j])
					TF[j] = true;
			}
		}
	}

	cin >> n;
	while(n)
	{
		cnt = 0;
		for (int i = n+1; i <= 2 * n; i++)
		{
			if (!TF[i])
				cnt++;
		}
		cout << cnt << '\n';
		cin >> n;
	}
	return 0;
}