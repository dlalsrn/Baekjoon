#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
int N, M, l, r;

Node upt(Node a, Node b)
{
	Node t;
	t.L_MAX = max(a.L_MAX, a.ALL + b.L_MAX);
	t.R_MAX = max(b.R_MAX, b.ALL + a.R_MAX);
	t.T_MAX = max(a.T_MAX, max(b.T_MAX, a.R_MAX + b.L_MAX));
	t.ALL = a.ALL + b.ALL;
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
		/*cout << n << ' ' << segtree[n].L_MAX << ' ' << segtree[n].R_MAX
			<< ' ' << segtree[n].T_MAX << ' ' << segtree[n].ALL << '\n';*/
	}
}

Node get_max(int n, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return { -1000000, -1000000, -1000000, 0 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int h = (int)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)));
	ary = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> ary[i];

	set_segtree(1, 0, N - 1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		Node t = get_max(1, 0, N - 1, l - 1, r - 1);
		cout << t.T_MAX << '\n';
	}

	return 0;
}