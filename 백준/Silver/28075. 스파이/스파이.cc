#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 0;
int v[2][3];

void recur(int cnt, int sum, int prev)
{
	if (cnt == N)
	{
		if (sum >= M) ans++;
		return;
	}

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			recur(cnt + 1, sum + (prev == j ? v[i][j] / 2 : v[i][j]), j);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> v[i][j];

	recur(0, 0, -1);

	cout << ans;

	return 0;
}