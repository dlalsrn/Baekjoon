#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << (((N + 1) % (N % 100) == 0) ? "Good\n" : "Bye\n");
	}

	return 0;
}