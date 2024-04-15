#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, a, b, c, cnt = 0, ans = 0;
vector <pi> node;
vector <bool> check;

void inorder(int n)
{
	if (node[n].first != -1)
	{
		ans++;
		inorder(node[n].first);
		ans++;
	}

	if (!check[n])
	{
		cnt++;
		check[n] = true;

		if (cnt == N)
		{
			cout << ans;
			return;
		}
	}

	if (node[n].second != -1)
	{
		ans++;
		inorder(node[n].second);
		ans++;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	node.resize(N + 1);
	check.resize(N + 1, false);

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		node[a] = make_pair(b, c);
	}

	inorder(1);

	return 0;
}