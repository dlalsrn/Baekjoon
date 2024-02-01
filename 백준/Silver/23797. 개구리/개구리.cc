#include <bits/stdc++.h>
using namespace std;

string x;
int K = 0, P = 0, cnt = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 'K')
		{
			if (P)
			{
				P--;
				K++;
			}
			else
			{
				cnt++;
				K++;
			}
		}
		else
		{
			if (K)
			{
				K--;
				P++;
			}
			else
			{
				cnt++;
				P++;
			}
		}
	}

	cout << cnt;
	return 0;
}