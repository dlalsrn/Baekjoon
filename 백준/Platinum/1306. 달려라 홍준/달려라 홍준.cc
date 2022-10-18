#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector <int> segtree;
vector <int> bright;
int N, M;

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = bright[start];
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

int get_max(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n];
	return max(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	cin >> N >> M;
	int h = (int)ceil(log2(N));
	segtree = vector<int>((1 << (h + 1)));
	bright = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> bright[i];

	set_segtree(1, 0, N - 1);

	for (int i = M - 1; i < N - (M - 1); i++)
	{
		int L, R;
		L = (i - (M - 1) < 0 ? 0 : i - (M - 1));
		R = (i + M - 1 > N - 1 ? N - 1 : i + M - 1);
		cout << get_max(1, 0, N - 1, L, R) << ' ';
	}

	return 0;
}