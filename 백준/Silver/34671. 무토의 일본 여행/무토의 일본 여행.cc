#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ti3 = tuple<int, int, int>;

int N, M, Q;
int u, v, w;
vector<ti3> node;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> Q;

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		
		if (u > v) swap(u, v);

		node.emplace_back(u, v, w);
	}

	sort(node.begin(), node.end());

	for (int i = 0; i < Q; ++i)
	{
		cin >> u >> v;

		if (u > v) swap(u, v);

		ti3 e = { u, v, 0 };
		auto it = lower_bound(node.begin(), node.end(), e);
		auto [prev, next, cost] = *it;

		if (it != node.end() && prev == u && next == v) cout << cost << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}