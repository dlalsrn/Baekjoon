#include <bits/stdc++.h>
using namespace std;

int N, zero, one;
string x;
vector <string> v;

void recur(int y, int x, int n)
{
	zero = 0;
	one = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[y + i][x + j] == '1') one++;
			else zero++;
		}
	}

	if (one == n * n) cout << 1;
	else if (zero == n * n) cout << 0;
	else
	{
		cout << '(';
		recur(y, x, n / 2);
		recur(y, x + n / 2, n / 2);
		recur(y + n / 2, x, n / 2);
		recur(y + n / 2, x + n / 2, n / 2);
		cout << ')';
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v = vector<string>(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	recur(0, 0, N);

	return 0;
}