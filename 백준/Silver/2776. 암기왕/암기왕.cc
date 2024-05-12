#include <bits/stdc++.h>
using namespace std;

int T, N, M, x;
vector <int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		v = vector<int>();

		for (int i = 0; i < N; i++)
		{
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> x;

			int j = lower_bound(v.begin(), v.end(), x) - v.begin();

			cout << (j != N && v[j] == x ? 1 : 0) << '\n';
		}
	}

	return 0;
}