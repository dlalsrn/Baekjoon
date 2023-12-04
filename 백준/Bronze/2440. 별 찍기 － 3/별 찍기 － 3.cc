#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
			cout << "*";
		cout << '\n';
	}

	return 0;
}