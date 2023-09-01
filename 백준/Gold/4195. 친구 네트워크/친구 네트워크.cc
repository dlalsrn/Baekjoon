// 친구 네트워크
// 23.08.31
// 분리집합
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using pi = pair<string, int>;

int T, N, u, v, ans = 0;
string a, b;
map <string, pair<string, int>> parent;

string find(string x)
{
	if (parent[x].first == x)
		return x;
	return parent[x].first = find(parent[x].first);
}

int merge(string x, string y)
{
	x = find(x), y = find(y);
	if (x == y)
		return parent[x].second;
	parent[y].first = x;
	parent[x].second += parent[y].second;
	return parent[x].second;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		parent = map<string, pair<string, int>>();

		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			if (!parent[a].second)
			{
				parent[a].first = a;
				parent[a].second = 1;
			}
			if (!parent[b].second)
			{
				parent[b].first = b;
				parent[b].second = 1;
			}
			cout << merge(a, b) << '\n';
		}
	}

	return 0;
}