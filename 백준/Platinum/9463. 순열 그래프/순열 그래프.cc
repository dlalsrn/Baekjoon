#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void segment(vector<int>& tree, int n, int start, int end)
{
	if (start == end)
		tree[n] = 0;
	else
	{
		segment(tree, n * 2, start, (start + end) / 2);
		segment(tree, n * 2 + 1, (start + end) / 2 + 1, end);
		tree[n] = 0;
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, num, h;
	long long s;
	vector <int> print;
	vector <int> index;
	vector <int> segtree;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		print = vector <int>(100001);
		index = vector <int>(100001);
		cin >> N;
		s = 0;
		h = (int)ceil(log2(N));
		segtree = vector <int>((1 << (h + 1)));
		segment(segtree, 1, 0, N - 1);
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			print[i] = num;
		}
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			index[num] = i;
		}
		for (int i = 0; i < N; i++)
		{
			s += sum(segtree, 1, 0, N-1, index[print[i]], N - 1);
			update(segtree, 1, 0, N - 1, index[print[i]], 1);
		}
		cout << s << '\n';
	}
	return 0;
}