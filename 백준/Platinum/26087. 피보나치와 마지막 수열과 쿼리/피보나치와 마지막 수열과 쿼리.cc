#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;

vector <int> lazy;
vector <int> segtree;
vector <int> fibo(1000001);
int N, M, l, r;

void Lazy(int n, int start, int end)
{
	if (lazy[n])
	{
		if (start != end)
		{
			int mid = (start + end) / 2;
			lazy[n * 2] = lazy[n] - (end - mid);
			lazy[n * 2 + 1] = lazy[n];
		}
		else
			segtree[n] = lazy[n];
		lazy[n] = 0;
	}
}

void update(int n, int start, int end, int left, int right, int change, int R)
{
	Lazy(n, start, end);
	if (right < start || left > end)
		return;
	if (left <= start && end <= right)
	{
		if (start != end)
		{
			int mid = (start + end) / 2;
			lazy[n * 2] = change - (R - mid);
			lazy[n * 2 + 1] = change;
		}
		else
			segtree[n] = change;
	}
	else
	{
		int mid = (start + end) / 2;
		if (right <= mid)
			update(n * 2, start, mid, left, right, change, R);
		else if (left > mid)
			update(n * 2 + 1, mid + 1, end, left, right, change, R);
		else
		{
			update(n * 2, start, mid, left, right, change - (R - mid), mid);
			update(n * 2 + 1, mid + 1, end, left, right, change, R);
		}
	}
}

int get(int n, int start, int end, int index)
{
	Lazy(n, start, end);
	if (start == end)
		return segtree[n];
	else
	{
		int mid = (start + end) / 2;
		if (index <= mid)
			return get(n * 2, start, mid, index);
		else
			return get(n * 2 + 1, mid + 1, end, index);
	}
}

void find_fibo()
{
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i <= 1000000; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;

	int h = (int)ceil(log2(N));
	segtree.resize(1 << (h + 1), 0);
	lazy.resize(1 << (h + 1), 0);
	find_fibo();

	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		update(1, 0, N - 1, l - 1, r - 1, r - l + 1, r - 1);
	}

	for (int i = 0; i < N; i++)
		cout << fibo[get(1, 0, N - 1, i)] << ' ';

	return 0;
}