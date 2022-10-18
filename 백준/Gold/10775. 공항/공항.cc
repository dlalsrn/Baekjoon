#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector <int> segtree;

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = start + 1;
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = max(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void update(int n, int start, int end, int index)
{
	if (start == end)
		segtree[n] = 0;
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index);
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
	int G, P, g, cnt = 0;;
	bool TF = false;
	cin >> G >> P;
	int h = (int)ceil(log2(G));
	segtree = vector<int>((1 << (h + 1)));

	set_segtree(1, 0, G - 1);

	for (int i = 0; i < P; i++)
	{
		cin >> g;
		int index = get_max(1, 0, G - 1, 0, g - 1);
		if (index && !TF)
		{
			cnt++;
			update(1, 0, G - 1, index - 1);
		}
		else
			TF = true;
	}

	cout << cnt;
	return 0;
}