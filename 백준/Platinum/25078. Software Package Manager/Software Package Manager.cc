#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <vector<int>> node;
vector <int> segtree;
vector <int> lazy;
vector <int> parent;
vector <int> sz;
vector <pair<int, int>> EULER_section;
vector <int> HLD_section;
vector <int> chain_number;
int N, M, cnt;

void DFS(int n, int pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (int x : node[n])
		if (x != pn)
			DFS(x, n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int start_chain)
{
	chain_number[n] = start_chain;
	HLD_section[n] = ++cnt;
	EULER_section[n].first = cnt;
	int heavy = -1;
	for (int x : node[n])
		if (x != pn && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;
	if (heavy != -1)
		HLD(heavy, n, start_chain);

	for (int x : node[n])
		if (x != pn && x != heavy)
			HLD(x, n, x);
	EULER_section[n].second = cnt;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = 1;
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] != -1)
	{
		segtree[n] = lazy[n] * (end - start + 1);
		if (start != end)
		{
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
		lazy[n] = -1;
	}
}

void update(int n, int start, int end, int left, int right, int change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (change == 1) // uninstall
		{
			segtree[n] = end - start + 1;
			if (start != end)
			{
				lazy[n * 2] = 1;
				lazy[n * 2 + 1] = 1;
			}
		}
		else // install
		{
			segtree[n] = 0;
			if (start != end)
			{
				lazy[n * 2] = 0;
				lazy[n * 2 + 1] = 0;
			}
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = segtree[n * 2] + segtree[n * 2 + 1];
	}
}

int get_sum(int n, int start, int end, int left, int right)
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int p, x;
	string ch;
	cin >> N;
	int h = (int)ceil(log2(N));
	node = vector<vector<int>>(N);
	segtree = vector<int>((1 << (h + 1)));
	lazy = vector<int>((1 << (h + 1)), -1);
	parent = vector<int>(N);
	sz = vector<int>(N);
	EULER_section = vector<pair<int, int>>(N);
	HLD_section = vector<int>(N);
	chain_number = vector<int>(N);

	for (int i = 1; i < N; i++)
	{
		cin >> p;
		node[p].push_back(i);
	}

	set_segtree(1, 0, N - 1);
	cnt = 0;
	DFS(0, -1);
	cnt = 0;
	HLD(0, -1, 0);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> x;
		if (ch == "install")
		{
			int sum = 0;
			while (chain_number[0] != chain_number[x])
			{
				sum += get_sum(1, 0, N - 1, HLD_section[chain_number[x]] - 1, HLD_section[x] - 1);
				update(1, 0, N - 1, HLD_section[chain_number[x]] - 1, HLD_section[x] - 1, 0);
				x = parent[chain_number[x]];
			}
			sum += get_sum(1, 0, N - 1, HLD_section[0] - 1, HLD_section[x] - 1);
			update(1, 0, N - 1, HLD_section[0] - 1, HLD_section[x] - 1, 0);
			cout << sum << '\n';
		}
		else
		{
			cout << (EULER_section[x].second - EULER_section[x].first + 1) -
				get_sum(1, 0, N - 1, EULER_section[x].first - 1, EULER_section[x].second - 1) << '\n';
			update(1, 0, N - 1, EULER_section[x].first - 1, EULER_section[x].second - 1, 1);
		}
	}
	return 0;
}