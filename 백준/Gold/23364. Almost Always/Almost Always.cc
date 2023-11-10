#include <bits/stdc++.h>
using namespace std;

int N, x;
map <int, int> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (m.find(x) != m.end())
		{
			cout << i + 1 << ' ' << m[x];
			break;
		}
		m[x] = i + 1;
	}

	return 0;
}