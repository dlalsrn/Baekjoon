#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		for (int i = 0; i < x.size() - 1; i++)
			if (x[i] != x[i + 1])
				cout << x[i];
		cout << x[x.size() - 1] << '\n';
	}

	return 0;
}