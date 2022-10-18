#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <vector<int>> node;
vector <int> sz;
vector <int> parent;
vector <int> chain_number;
vector <int> section;
vector <int> segtree;
vector <vector<int>> chain;
int cnt;

void DFS(int n, int pn)
{
	parent[n] = pn;
	sz[n] = ++cnt;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn)
			DFS(node[n][i], n);
	sz[n] = cnt - sz[n] + 1;
}

void HLD(int n, int pn, int cur_chain)
{
	chain_number[n] = cur_chain;
	chain[cur_chain].push_back(n);
	section[n] = ++cnt;

	int heavy = -1;
	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn && (heavy == -1 || sz[node[n][i]] > sz[heavy]))
			heavy = node[n][i];
	if (heavy != -1)
		HLD(heavy, n, cur_chain);

	for (int i = 0; i < node[n].size(); i++)
		if (node[n][i] != pn && node[n][i] != heavy)
			HLD(node[n][i], n, node[n][i]);
}

int upt(int a, int b)
{
	if (a == -1 && b == -1)
		return -1;
	else if (a != -1 && b != -1)
		return section[a] < section[b] ? a : b;
	else
		if (a != -1)
			return a;
		else
			return b;
}

void update(int n, int start, int end, int index, int change)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(n * 2, start, (start + end) / 2, index, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
	else
	{
		if (segtree[n] == -1)
			segtree[n] = change;
		else
			segtree[n] = -1;
	}
}

int get_black(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return -1;
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_black(n * 2, start, (start + end) / 2, left, right), get_black(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, n1, n2, ch;
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)), -1);
	node = vector<vector<int>>(N + 1);
	sz = vector<int>(N + 1);
	parent = vector<int>(N + 1);
	chain_number = vector<int>(N + 1);
	chain = vector<vector<int>>(N + 1);
	section = vector<int>(N + 1);
	
	for (int i = 0; i < N - 1; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	cnt = 0;
	DFS(1, 0);
	cnt = 0;
	HLD(1, 0, 1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ch >> n1;
		if (ch == 1)
			update(1, 0, N - 1, section[n1] - 1, n1);
		else
		{
			int n = -1;
			while(true)
			{
				n = upt(n, get_black(1, 0, N - 1, section[chain_number[n1]] - 1, section[n1] - 1));
				if (chain_number[n1] != 1)
					n1 = parent[chain_number[n1]];
				else
					break;
			}
			cout << n << '\n';
		}
	}
	return 0;
}