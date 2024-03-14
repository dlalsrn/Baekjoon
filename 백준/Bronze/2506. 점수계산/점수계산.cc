#include <bits/stdc++.h>
using namespace std;

int N, x, pre = -1, cnt, sum = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 1)
		{
			if (pre == 1) sum += cnt++;
			else
			{
				pre = 1;
				cnt = 2;
				sum++;
			}
		}
		else pre = 0;
	}

	cout << sum;

	return 0;
}