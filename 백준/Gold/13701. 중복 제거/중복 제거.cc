#include <bits/stdc++.h>
using namespace std;

int N;
vector<bool> v(33554433, false);

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (cin >> N)
	{
		if (!v[N])
		{
			cout << N << ' ';
			v[N] = true;
		}
	}

	return 0;
}