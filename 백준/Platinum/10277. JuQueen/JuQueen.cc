#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define inf 4587520
using namespace std;

typedef struct
{
	int MX;
	int MN;
}NODE;

vector <NODE> segtree;
vector <int> lazy;
int N, M, S, l, r, c;
string ch;

NODE upt(NODE a, NODE b)
{
	return { max(a.MX, b.MX), min(a.MN, b.MN) };
}

void Lazy(int n, int start, int end)
{
	if (lazy[n] != 0)
	{
		segtree[n].MX += lazy[n];
		segtree[n].MN += lazy[n];
		if (start != end)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int n, int start, int end, int left, int right, int change)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		segtree[n].MX += change;
		segtree[n].MN += change;
		if (start != end)
		{
			lazy[n * 2] += change;
			lazy[n * 2 + 1] += change;
		}
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

NODE get_MXMN(int n, int start, int end, int left, int right)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return {0, inf};
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_MXMN(n * 2, start, (start + end) / 2, left, right), get_MXMN(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> M;

	int h = (int)ceil(log2(N));
	segtree = vector<NODE>((1 << (h + 1)), {0, 0});
	lazy = vector<int>((1 << (h + 1)), 0);

	for (int i = 0; i < M; i++)
	{
		cin >> ch;
		if (ch == "state")
		{
			cin >> l;
			cout << get_MXMN(1, 0, N - 1, l, l).MX << '\n';
		}
		else if (ch == "groupchange")
		{
			cin >> l >> r >> c;
			NODE t = get_MXMN(1, 0, N - 1, l, r);
			if (c < 0)
			{
				if (abs(c) > t.MN)
				{
					cout << -t.MN << '\n';
					update(1, 0, N - 1, l, r, -t.MN);
				}
				else
				{
					cout << c << '\n';
					update(1, 0, N - 1, l, r, c);
				}
			}
			else
			{
				if (S < t.MX + c)
				{
					cout << S - t.MX << '\n';
					update(1, 0, N - 1, l, r, S - t.MX);
				}
				else
				{
					cout << c << '\n';
					update(1, 0, N - 1, l, r, c);
				}
			}
		}
		else
		{
			cin >> l >> c;
			NODE t = get_MXMN(1, 0, N - 1, l, l);
			if (c < 0)
			{
				if (abs(c) > t.MN)
				{
					cout << -t.MN << '\n';
					update(1, 0, N - 1, l, l, -t.MN);
				}
				else
				{
					cout << c << '\n';
					update(1, 0, N - 1, l, l, c);
				}
			}
			else
			{
				if (S < t.MX + c)
				{
					cout << S - t.MX << '\n';
					update(1, 0, N - 1, l, l, S - t.MX);
				}
				else
				{
					cout << c << '\n';
					update(1, 0, N - 1, l, l, c);
				}
			}
		}
	}

	return 0;
}