#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> ans(3), cnt(3);
vector <vector<int>> v;

void recur(int y, int x, int n)
{
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[y + i][x + j] == -1) cnt[0]++;
			else if (v[y + i][x + j] == 0) cnt[1]++;
			else cnt[2]++;
		}
	}

	if (cnt[0] == n * n) ans[0]++;
	else if (cnt[1] == n * n) ans[1]++;
	else if (cnt[2] == n * n) ans[2]++;
	else
	{
		recur(y, x, n / 3);
		recur(y, x + n / 3, n / 3);
		recur(y, x + n / 3 * 2, n / 3);
		recur(y + n / 3, x, n / 3);
		recur(y + n / 3, x + n / 3, n / 3);
		recur(y + n / 3, x + n / 3 * 2, n / 3);
		recur(y + n / 3 * 2, x, n / 3);
		recur(y + n / 3 * 2, x + n / 3, n / 3);
		recur(y + n / 3 * 2, x + n / 3 * 2, n / 3);
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

	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';

	return 0;
}