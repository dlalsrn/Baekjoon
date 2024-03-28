#include <bits/stdc++.h>
using namespace std;

int N, M, K, x, ans = 0;
vector <int> parent;
vector <bool> T;
vector <vector<int>> party;
vector <bool> check_party;

int find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (T[x]) parent[y] = x;
	else if (T[y]) parent[x] = y;
	else parent[y] = x;
}

bool same(int x, int y)
{
	x = find(x);
	y = find(y);
	return (x == y ? true : false);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> K;

	T.resize(N + 1, false);
	parent.resize(N + 1);
	check_party.resize(M, false);
	iota(parent.begin(), parent.end(), 0);

	for (int k = 0; k < K; k++)
	{
		cin >> x;
		T[x] = true;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> K;
		int pre = 0;
		vector <int> t;
		for (int k = 0; k < K; k++)
		{
			cin >> x;
			t.push_back(x);
			if (k && !same(pre, x)) merge(pre, x);
			pre = x;
		}
		party.push_back(t);
	}

	for (int i = 1; i <= N; i++)
	{
		int t = find(i);
		if (!T[t]) continue;

		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < party[j].size(); k++)
			{
				if (party[j][k] == i)
				{
					check_party[j] = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < M; i++)
		if (!check_party[i])
			ans++;

	cout << ans;

	return 0;
}