#include <bits/stdc++.h>
using namespace std;

vector <int> v(5);
int mx = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
		cin >> v[i];

	for (int n = 1; n <= 15; n++)
	{
		if (n <= 3)
		{
			for (int a = 0; a <= n; a++)
			{
				for (int b = 0; a + b <= n; b++)
				{
					for (int c = 0; a + b + c <= n; c++)
					{
						for (int d = 0; a + b + c + d <= n; d++)
						{
							int e = n - (a + b + c + d);
							int t = a * 1 + b * 2 + c * 3 + d * 4 + e * 5;
							if (t > 10)
								continue;
							mx = max(mx, a * v[0] + b * v[1] + c * v[2] + d * v[3] + e * v[4]);
						}
					}
				}
			}
		}
		else
		{
			for (int a = 0; a <= n; a++)
			{
				for (int b = 0; a + b <= n; b++)
				{
					for (int c = 0; a + b + c <= n; c++)
					{
						for (int d = 0; a + b + c + d <= n; d++)
						{
							int e = n - (a + b + c + d);
							int t = a * 1 + b * 2 + c * 3 + d * 4 + e * 5;
							if (t > 15)
								continue;
							mx = max(mx, a * v[0] + b * v[1] + c * v[2] + d * v[3] + e * v[4]);
						}
					}
				}
			}
		}
	}

	cout << mx;

	return 0;
}