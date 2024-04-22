#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, Q, a, b, x;
vector <int> p, parent, color, ans;
vector <set<int>> set_color;
vector <pi> query;

int find(int x)
{
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (set_color[x].size() < set_color[y].size()) swap(set_color[x], set_color[y]);

	for (auto t : set_color[y]) set_color[x].insert(t);
	set_color[y].clear();
	p[y] = x;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> Q;

	parent.resize(N + 1);
	p.resize(N + 1);
	iota(p.begin(), p.end(), 0);
	color.resize(N + 1);
	set_color.resize(N + 1);

	for (int i = 2; i <= N; i++) cin >> parent[i];
	for (int i = 1; i <= N; i++) cin >> color[i];
	for (int i = 1; i <= N; i++) set_color[i].insert(color[i]);

	for (int i = 0; i < N + Q - 1; i++)
	{
		cin >> a >> b;
		query.emplace_back(a, b);
	}

	for (int i = query.size() - 1; i >= 0; i--)
	{
		a = query[i].first;
		b = query[i].second;

		if (a == 1) merge(parent[b], b);
		else ans.push_back(set_color[b = find(b)].size());
	}

	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';

	return 0;
}