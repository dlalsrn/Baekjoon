#include <bits/stdc++.h>
using namespace std;

int N, ans_W = 0, ans_B = 0, W, B;
vector <vector<int>> v;

void recur(int y, int x, int n)
{
	W = 0;
	B = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[y + i][x + j]) B++;
			else W++;
		}
	}

	if (W == n * n) ans_W++;
	else if (B == n * n) ans_B++;
	else
	{
		recur(y, x, n / 2);
		recur(y + n / 2, x, n / 2);
		recur(y, x + n / 2, n / 2);
		recur(y + n / 2, x + n / 2, n / 2);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v = vector<vector<int>>(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> v[i][j];

	recur(0, 0, N);

	cout << ans_W << '\n' << ans_B << '\n';

	return 0;
}