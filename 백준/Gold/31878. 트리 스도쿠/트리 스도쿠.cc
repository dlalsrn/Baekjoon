#include <bits/stdc++.h>
using namespace std;

int N, x, a, b, cnt = 0;
vector <vector<int>> node;
vector <pair<int, int>> v;
vector <int> match;
vector <bool> check;
queue <int> q;

void bfs()
{
	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		match[n] = v[cnt++].second;

		for (int x : node[n])
		{
			if (!check[x])
			{
				check[x] = true;
				q.push(x);
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node.resize(N + 1);
	match.resize(N + 1);
	check.resize(N + 1, false);

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.emplace_back(x, i + 1);
	}

	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	sort(v.begin(), v.end());

	q.push(1);
	check[1] = true;
	bfs();

	cout << "YES\n";
	for (int i = 1; i <= N; i++) cout << match[i] << ' ';

	return 0;
}
