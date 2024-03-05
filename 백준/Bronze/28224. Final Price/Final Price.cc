#include <bits/stdc++.h>
using namespace std;

int N, x, sum = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
	}

	cout << sum;

	return 0;
}