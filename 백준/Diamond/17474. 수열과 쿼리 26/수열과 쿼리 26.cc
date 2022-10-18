// 수열과 쿼리 26
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

typedef struct
{
	ll mx; // 제일 큰 값
	ll mx2; // 2번 째로 큰 값
	ll mx_cnt; // 제일 큰 값의 개수
	ll sum; // 노드의 합
}Node;
vector <Node> segtree;
vector <ll> node;

Node renew(Node a, Node b)
{
	if (a.mx == b.mx)
		return { a.mx, max(a.mx2, b.mx2), a.mx_cnt + b.mx_cnt, a.sum + b.sum };
	if (a.mx < b.mx)
		swap(a, b);
	return { a.mx, max(a.mx2, b.mx), a.mx_cnt, a.sum + b.sum };
}

void set_segtree(ll n, ll start, ll end)
{
	if (start == end)
		segtree[n] = { node[start], -1, 1, node[start] };
	else
	{
		set_segtree(n * 2, start, (start + end) / 2);
		set_segtree(n * 2 + 1, (start + end) / 2 + 1, end);
		segtree[n] = renew(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

void push(ll n, ll start, ll end)
{
	if (start != end)
	{
		for (ll i = n * 2; i <= n * 2 + 1; i++)
		{
			// 부모보다 자식의 max 값이 클 때만 바꿔줌
			if (segtree[n].mx < segtree[i].mx)
			{
				segtree[i].sum -= (segtree[i].mx_cnt * (segtree[i].mx - segtree[n].mx));
				segtree[i].mx = segtree[n].mx;
			}
		}
	}
}


void update(ll n, ll start, ll end, ll left, ll right, ll change)
{
	push(n, start, end);
	if (right < start || left > end || segtree[n].mx <= change)
		return;
	if (left <= start && end <= right && segtree[n].mx2 < change)
	{
		segtree[n].sum -= (segtree[n].mx_cnt * (segtree[n].mx - change));
		segtree[n].mx = change;
		//push(n, start, end);
	}
	else
	{
		update(n * 2, start, (start + end) / 2, left, right, change);
		update(n * 2 + 1, (start + end) / 2 + 1, end, left, right, change);
		segtree[n] = renew(segtree[n * 2], segtree[n * 2 + 1]);
	}
}

ll get_max(ll n, ll start, ll end, ll left, ll right)
{
	push(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].mx;
	return max(get_max(n * 2, start, (start + end) / 2, left, right), get_max(n * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll get_sum(ll n, ll start, ll end, ll left, ll right)
{
	push(n, start, end);
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return segtree[n].sum;
	return get_sum(n * 2, start, (start + end) / 2, left, right) + get_sum(n * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M, ch, l, r, x;
	cin >> N;
	ll h = (ll)ceil(log2(N));
	segtree = vector <Node>((1 << (h + 1)));
	node = vector <ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> node[i];

	set_segtree(1, 0, N - 1);

	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		cin >> ch >> l >> r;
		if (ch == 1)
		{
			cin >> x;
			update(1, 0, N - 1, l - 1, r - 1, x);
		}
		else if (ch == 2)
			cout << get_max(1, 0, N - 1, l - 1, r - 1) << '\n';
		else
			cout << get_sum(1, 0, N - 1, l - 1, r - 1) << '\n';
	}

	return 0;
}