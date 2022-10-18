#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int cnt;

void segment(vector<int>& tree, int n, int start, int end)
{
	if (start == end)
	{
		if (cnt != 0)
		{
			tree[n] = 1;
			cnt--;
		}
		else
			tree[n] = 0;
	}
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

int sum(vector<int>& tree, int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return tree[n];
	return sum(tree, n * 2, start, (start + end) / 2, left, right) + sum(tree, n*2+1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, M, num, s, count;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		count = N;
		cnt = N;
		int h = (int)ceil(log2(100000 + N - 1));
		vector <int> index(N + 1);
		for (int i = 0; i < N; i++)
			index[N - i] = i;
		vector <int> segtree((1 << (h + 1)));
		segment(segtree, 1, 0, 100000 + N - 1);
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			s = sum(segtree, 1, 0, 100000 + N - 1, index[num] + 1, 100000 + N - 1);
			cout << s << ' ';
			update(segtree, 1, 0, 100000 + N - 1, count, 1);
			update(segtree, 1, 0, 100000 + N - 1, index[num], -1);
			index[num] = count++;
		}
		cout << '\n';
	}
}