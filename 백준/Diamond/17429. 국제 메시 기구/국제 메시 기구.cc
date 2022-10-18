#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned int ui;
vector <vector<ui>> node;
vector <ui> segtree;
vector <pair<ui, ui>> lazy;
vector <pair<ui, ui>> Euler_section;
vector <ui> HLD_section;
vector <ui> parent;
vector <ui> sz;
vector <ui> depth;
vector <ui> chain_number;
vector <ui> chain_index;
vector <vector<ui>> chain;
ui cnt, N, Q;

void DFS(ui n, ui pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (ui x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(ui n, ui pn, ui start_chain, ui d)
{
	depth[n] = d;
	chain_number[n] = start_chain;
	chain_index[n] = chain[start_chain].size();
	chain[start_chain].push_back(n);

	HLD_section[n] = ++cnt;
	Euler_section[n].first = cnt;
	int heavy = -1;
	for (ui x : node[n])
		if (x != pn && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;
	if (heavy != -1)
		HLD(heavy, n, start_chain, d);

	for (ui x : node[n])
		if (x != pn && x != heavy)
			HLD(x, n, x, d + 1);
	Euler_section[n].second = cnt;
}

ui LCA(ui X, ui Y)
{
	while (chain_number[X] != chain_number[Y])
	{
		if (depth[X] > depth[Y])
			X = parent[chain_number[X]];
		else
			Y = parent[chain_number[Y]];
	}
	return chain_index[X] > chain_index[Y] ? Y : X;
}

void Lazy(ui n, ui start, ui end)
{
	if (lazy[n].first != 1 || lazy[n].second != 0)
	{
		segtree[n] *= lazy[n].first;
		segtree[n] += lazy[n].second * (end - start + 1);
		if (start != end)
		{
			lazy[n * 2].first *= lazy[n].first;
			lazy[n * 2].second *= lazy[n].first;
			lazy[n * 2].second += lazy[n].second;
			lazy[n * 2 + 1].first *= lazy[n].first;
			lazy[n * 2 + 1].second *= lazy[n].first;
			lazy[n * 2 + 1].second += lazy[n].second;
		}
		lazy[n].first = 1;
		lazy[n].second = 0;
	}
}

void update(ui n, ui start, ui end, ui left, ui right, ui change, char op)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (op == '+')
		{
			segtree[n] += change * (end - start + 1);
			if (start != end)
			{
				lazy[n * 2].second += change;
				lazy[n * 2 + 1].second += change;
			}
		}
		else
		{
			segtree[n] *= change;
			if (start != end)
			{
				lazy[n * 2].first *= change;
				lazy[n * 2].second *= change;
				lazy[n * 2 + 1].first *= change;
				lazy[n * 2 + 1].second *= change;
			}
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change, op);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change, op);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

ui get_sum(ui n, ui start, ui end, ui left, ui right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ui ch, X, Y, V;
	cin >> N >> Q;
	ui h = (ui)ceil(log2(N));
	segtree = vector<ui>((1 << (h + 1)), 0);
	lazy = vector<pair<ui, ui>>((1 << (h + 1)), { 1, 0 });
	node = vector <vector<ui>>(N + 1);
	Euler_section = vector<pair<ui, ui>>(N + 1);
	HLD_section = vector<ui>(N + 1);
	parent = vector<ui>(N + 1);
	sz = vector<ui>(N + 1);
	depth = vector<ui>(N + 1);
	chain_number = vector<ui>(N + 1);
	chain_index = vector<ui>(N + 1);
	chain = vector<vector<ui>>(N + 1);

	for (ui i = 0; i < N - 1; i++)
	{
		cin >> X >> Y;
		node[X].push_back(Y);
		node[Y].push_back(X);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1, 0);

	for (ui i = 0; i < Q; i++)
	{
		cin >> ch >> X;
		if (ch == 1)
		{
			cin >> V;
			update(1, 0, N - 1, Euler_section[X].first - 1, Euler_section[X].second - 1, V, '+');
		}
		else if (ch == 2)
		{
			cin >> Y >> V;
			ui t = LCA(X, Y);
			while (chain_number[t] != chain_number[X])
			{
				update(1, 0, N - 1, HLD_section[chain_number[X]] - 1, HLD_section[X] - 1, V, '+');
				X = parent[chain_number[X]];
			}
			if (t != X)
				update(1, 0, N - 1, HLD_section[t], HLD_section[X] - 1, V, '+');
			while (chain_number[t] != chain_number[Y])
			{
				update(1, 0, N - 1, HLD_section[chain_number[Y]] - 1, HLD_section[Y] - 1, V, '+');
				Y = parent[chain_number[Y]];
			}
			if(t != Y)
				update(1, 0, N - 1, HLD_section[t], HLD_section[Y] - 1, V, '+');
			update(1, 0, N - 1, HLD_section[t] - 1, HLD_section[t] - 1, V, '+');
		}
		else if (ch == 3)
		{
			cin >> V;
			update(1, 0, N - 1, Euler_section[X].first - 1, Euler_section[X].second - 1, V, '*');
		}
		else if (ch == 4)
		{
			cin >> Y >> V;
			ui t = LCA(X, Y);
			while (chain_number[t] != chain_number[X])
			{
				update(1, 0, N - 1, HLD_section[chain_number[X]] - 1, HLD_section[X] - 1, V, '*');
				X = parent[chain_number[X]];
			}
			if (t != X)
				update(1, 0, N - 1, HLD_section[t], HLD_section[X] - 1, V, '*');
			while (chain_number[t] != chain_number[Y])
			{
				update(1, 0, N - 1, HLD_section[chain_number[Y]] - 1, HLD_section[Y] - 1, V, '*');
				Y = parent[chain_number[Y]];
			}
			if (t != Y)
				update(1, 0, N - 1, HLD_section[t], HLD_section[Y] - 1, V, '*');
			update(1, 0, N - 1, HLD_section[t] - 1, HLD_section[t] - 1, V, '*');
		}
		else if (ch == 5)
			cout << get_sum(1, 0, N - 1, Euler_section[X].first - 1, Euler_section[X].second - 1) << '\n';
		else if (ch == 6)
		{
			cin >> Y;
			ui sum = 0;
			ui t = LCA(X, Y);
			while (chain_number[t] != chain_number[X])
			{
				sum += get_sum(1, 0, N - 1, HLD_section[chain_number[X]] - 1, HLD_section[X] - 1);
				X = parent[chain_number[X]];
			}
			if (t != X)
				sum += get_sum(1, 0, N - 1, HLD_section[t], HLD_section[X] - 1);
			while (chain_number[t] != chain_number[Y])
			{
				sum += get_sum(1, 0, N - 1, HLD_section[chain_number[Y]] - 1, HLD_section[Y] - 1);
				Y = parent[chain_number[Y]];
			}
			if (t != Y)
				sum += get_sum(1, 0, N - 1, HLD_section[t], HLD_section[Y] - 1);
			sum += get_sum(1, 0, N - 1, HLD_section[t] - 1, HLD_section[t] - 1);
			cout << sum << '\n';
		}
	}
	return 0;
}