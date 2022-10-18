// 순열복원
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <int> order(100000);
int cnt;

void segment(vector<int>& tree, int n, int start, int end)
{
	if (start == end)
		tree[n] = 1;
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
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
	{
		order[start] = cnt--;
		return start;
	}
	if (tree[n * 2] >= index)
		return find(tree, n * 2, start, (start + end) / 2, index);
	else
	{
		index -= tree[n * 2];
		return find(tree, n * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, num, index;
	cin >> N;
	cnt = N;
	int h = (int)ceil(log2(N));
	vector <int> segtree((1 << (h + 1)));
	vector <int> print;
	segment(segtree, 1, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		print.push_back(num);
	}

	for (int i = N-1; i >= 0; i--)
	{
		index = find(segtree, 1, 0, N - 1, i - print[i] + 1);
		update(segtree, 1, 0, N - 1, index, -1);
	}
	for (int i = 0; i < N; i++)
		cout << order[i] << ' ';
	return 0;
}