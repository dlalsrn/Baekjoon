#include <bits/stdc++.h>
using namespace std;

int N, Q, M, x, ch, a, b;
vector <set<int>> s;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	s.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> x;
			s[i].insert(x);
		}
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> ch >> a;
		a--;
		if (ch == 1)
		{
			cin >> b;
			b--;
			if (s[a].size() < s[b].size()) swap(s[a], s[b]);

			for (auto t = s[b].begin(); t != s[b].end(); t++) s[a].insert(*t);

			s[b].clear();
		}

		else cout << s[a].size() << '\n';
	}
	return 0;
}