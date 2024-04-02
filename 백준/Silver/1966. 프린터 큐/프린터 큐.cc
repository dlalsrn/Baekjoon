#include <bits/stdc++.h>
using namespace std;

int T, N, M, x;
vector <int> v;
queue <pair<int, int>> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;

		v = vector<int>();
		q = queue<pair<int, int>>();

		for (int i = 0; i < N; i++)
		{
			cin >> x;
			v.push_back(x);
			q.push(make_pair(x, i));
		}
		sort(v.begin(), v.end(), greater<>());

		for (int i = 0; i < N; i++)
		{
			while (q.front().first != v[i])
			{
				q.push(q.front());
				q.pop();
			}
			if (q.front().second == M)
			{
				cout << i + 1 << '\n';
				break;
			}
			q.pop();
		}
	}

	return 0;
}