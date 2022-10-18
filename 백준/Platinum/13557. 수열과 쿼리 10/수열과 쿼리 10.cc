#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define NOT -100001
using namespace std;
typedef long long ll;
typedef struct
{
	ll L_MAX;
	ll R_MAX;
	ll T_MAX;
	ll ALL;
}Node;

vector <Node> segtree;
vector <ll> value;

Node upt(Node Left, Node Right)
{
	Node t;
	t.L_MAX = max(Left.L_MAX, Left.ALL + Right.L_MAX);
	t.R_MAX = max(Right.R_MAX, Right.ALL + Left.R_MAX);
	t.T_MAX = max({ Left.T_MAX, Right.T_MAX, Left.R_MAX + Right.L_MAX });
	t.ALL = Left.ALL + Right.ALL;
	return t;
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { value[start], value[start], value[start], value[start] };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = upt(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

Node get_max(ll n, ll start, ll end, ll left, ll right)
{
	if (right < start || left > end)
		return { NOT,NOT,NOT,0 };
	if (left <= start && end <= right)
		return segtree[n];
	return upt(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, x1, x2, y1, y2;
	cin >> N;
	ll h = (ll)ceil(log2(N));
	segtree = vector<Node>((1 << (h + 1)));
	value = vector<ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> value[i];

	set_segtree(1, 0, N - 1);

	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		Node Left, Mid, Right;

		if (y1 < x2) // 왼쪽과 오른쪽 구간이 안 겹칠 때
		{
			Left = get_max(1, 0, N - 1, x1 - 1, y1 - 1);
			Right = get_max(1, 0, N - 1, x2 - 1, y2 - 1);
			Mid = get_max(1, 0, N - 1, y1, x2 - 2);
			cout << Left.R_MAX + Mid.ALL + Right.L_MAX << '\n';
		}
		else // 구간이 겹칠 때
		{
			Left = get_max(1, 0, N - 1, x1 - 1, x2 - 2);
			Right = get_max(1, 0, N - 1, y1, y2 - 1);
			Mid = get_max(1, 0, N - 1, x2 - 1, y1 - 1);
			cout << max({ Left.R_MAX + Mid.L_MAX, Mid.R_MAX + Right.L_MAX, Mid.T_MAX, Left.R_MAX + Mid.ALL + Right.L_MAX }) << '\n';
		}
	}

	return 0;
}