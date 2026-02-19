#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
int TC = 1;
unordered_map<string, string> um;
unordered_map<string, bool> check;

void DFS(string n)
{
	string next = um[n];
	if (!check[next])
	{
		check[next] = true;
		DFS(next);
	}
	else
	{
		++cnt;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (true)
	{
		cin >> N;
		if (!N)
		{
			break;
		}

		um.clear();
		check.clear();
		cnt = 0;

		for (int i = 0; i < N; ++i)
		{
			string u, v;
			cin >> u >> v;
			um[u] = v;
		}

		for (auto it : um)
		{
			string s = it.first;
			if (!check[s])
			{
				check[s] = true;
				DFS(s);
			}
		}

		cout << TC++ << ' ' << cnt << '\n';
	}

	return 0;
}