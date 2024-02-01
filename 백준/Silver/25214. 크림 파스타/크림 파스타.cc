#include <bits/stdc++.h>
using namespace std;

int N, mx = 0;
vector <int> v;
vector <int> t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N);

	int l = 0, r = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (i == 0) l = r = x;
		else
		{
			if (r < x) r = x;
			else if (l > x) l = r = x;
		}
		mx = max(mx, r - l);

		cout << mx << ' ';
	}

	return 0;
}