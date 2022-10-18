#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define inf 1000000000
using namespace std;

typedef struct
{
	int L_MAX; // 구간의 맨 왼쪽 값을 포함한 가장 큰 연속합
	int R_MAX; // 구간의 맨 오른쪽 값을 포함한 가장 큰 연속합
	int T_MAX; // 구간에서 가장 큰 엽속합
	int ALL; // 구간의 모든 값의 합
}Node;
vector <Node> segtree;
vector <int> ary;
int N, M, U, V, ch, l, r;

Node upt(Node Left, Node Right)
{
	Node t;
	t.L_MAX = max(Left.L_MAX, Left.ALL + Right.L_MAX);
	t.R_MAX = max(Right.R_MAX, Right.ALL + Left.R_MAX);
	t.T_MAX = max(Left.T_MAX, max(Right.T_MAX, Left.R_MAX + Right.L_MAX));
	t.ALL = Left.ALL + Right.ALL;
	return t;
}

void set_segtree(int n, int start, int end)
{
	if (start == end)
		segtree[n] = { ary[start], ary[start], ary[start], ary[start] };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void update(int n, int start, int end, int index, int change)
{
	if (start == end)
		segtree[n] = { change, change, change, change };
	else
	{
		if (index <= (start + end) / 2)
			update(n * 2, start, (start + end) / 2, index, change);
		else
			update(n * 2 + 1, (start + end) / 2 + 1, end, index, change);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

Node get_max(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return { -inf, -inf, -inf, 0 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> U >> V;
	int h = (int)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)));
	ary = vector<int>(N);

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
		ary[i] = U * ary[i] + V;
	}

	set_segtree(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		cin >> ch >> l >> r;
		if (ch)
			update(1, 0, N - 1, l - 1, r * U + V);
		else
			cout << get_max(1, 0, N - 1, l - 1, r - 1).T_MAX - V << '\n';
	}

	return 0;
}