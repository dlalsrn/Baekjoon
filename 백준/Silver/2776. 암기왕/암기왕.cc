#include <bits/stdc++.h>
using namespace std;

int T, N, M, x;
set <int> s;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		s.clear();

		for (int i = 0; i < N; i++)
		{
			cin >> x;
			s.insert(x);
		}

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> x;
			
			cout << (s.find(x) != s.end() ? 1 : 0) << '\n';
		}
	}

	return 0;
}