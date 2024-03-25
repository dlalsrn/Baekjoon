#include <bits/stdc++.h>
using namespace std;

int N, cnt, sum;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		cnt = sum = 0;
		for (int j = 0; j < x.size(); j++)
		{
			if (x[j] == 'O') sum += ++cnt;
			else cnt = 0;
		}

		cout << sum << '\n';
	}

	return 0;
}