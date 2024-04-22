#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector <set<int>> s;
vector <int> ans;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	s.resize(N + 1);
	ans.resize(N + 1);

	for (int i = 1; i <= N; i++) s[i].insert(i);

	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		if (s[a].size() > s[b].size()) swap(s[a], s[b]);

		for (auto x : s[a]) s[b].insert(x);
		s[a].clear();
	}

	for (int i = 1; i <= N; i++)
		for (auto x : s[i]) ans[x] = i;

	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';

	return 0;
}