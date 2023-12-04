#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cout << i << ' ';
		if (i % 6 == 0 || i == N)
			cout << "Go! ";
	}

	return 0;
}