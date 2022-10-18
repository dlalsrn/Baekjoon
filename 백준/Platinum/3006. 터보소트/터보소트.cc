#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void segment(vector<int>& tree, int n, int start, int end)
{
	if (start == end)
		tree[n] = 1;
	else
	{
		segment(tree, n*2, start, (start + end) / 2);
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

int sum(vector<int>& tree, int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return tree[n];
	return sum(tree, n * 2, start, (start + end) / 2, left, right) + sum(tree, n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	int N, num, start, end;
	cin >> N;
	start = 1, end = N;
	vector<int> index(100001);
	int h = (int)ceil(log2(N+1));
	vector<int> segtree((1 << (h+1)));
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		index[num] = i;
	}
	segment(segtree, 1, 1, N);
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			num = sum(segtree, 1, 1, N, 1, index[start]-1);
			update(segtree, 1, 1, N, index[start], -1);
			cout << num << '\n';
			start++;
		}
		else
		{
			num = sum(segtree, 1, 1, N, index[end]+1, N);
			update(segtree, 1, 1, N, index[end], -1);
			cout << num << '\n';
			end--;
		}
	}
	return 0;
}