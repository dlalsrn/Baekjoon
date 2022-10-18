#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void segment(vector<int>& node, vector<int>& tree, int n, int start, int end)
{
	if (start == end)
		tree[n] = node[start];
	else
	{
		segment(node, tree, n * 2, start, (start + end) / 2);
		segment(node, tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

void update(vector<int>& tree, int n, int start, int end, int index, int change)
{
	if (index < start || index > end)
		return;
	if (start != end)
	{
		update(tree, n * 2, start, (start + end) / 2, index, change);
		update(tree, n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
	else if (start == end && start == index)
		tree[n] += change;
}

int find(vector<int>& tree, int n, int start, int end, int index)
{
	if (start == end)
		return start;
	if (tree[n * 2] >= index)
		return find(tree, n * 2, start, (start + end) / 2, index);
	else
		return find(tree, n * 2 + 1, (start + end) / 2 + 1, end, index - tree[n * 2]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, index, num;
	cin >> N;
	int h = (int)ceil(log2(N));
	vector<int> node(N);
	vector<int> segtree((1 << (h + 1)));

	for (int i = 0; i < N; i++)
		cin >> node[i];
	segment(node, segtree, 1, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cin >> index;
		num = find(segtree, 1, 0, N - 1, index);
		update(segtree, 1, 0, N - 1, num, -node[num]);
		cout << num + 1 << ' ';
	}
	return 0;
}