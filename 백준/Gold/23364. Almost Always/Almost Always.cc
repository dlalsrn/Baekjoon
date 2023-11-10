#include <bits/stdc++.h>
using namespace std;

int N, x, i;
map <int, int> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> x;
		if (m[x])
		{
			cout << i + 1 << ' ' << m[x];
			return 0;
		}
		m[x] = i + 1;
	}
}