// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, S, cnt = 0;
vector <ll> v;
map <ll, ll> m;

void right(ll mid, ll sum)
{
	if (mid == N)
	{
		m[sum]++;
		return;
	}
	right(mid + 1, sum + v[mid]);
	right(mid + 1, sum);
}

void left(ll start, ll sum)
{
	if (start == N / 2)
	{
		cnt += m[S - sum];
		return;
	}
	left(start + 1, sum + v[start]);
	left(start + 1, sum);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> S;

	v.resize(N);

	for (int i = 0; i < N; i++) cin >> v[i];

	right(N / 2, 0);
	left(0, 0);

	cout << (S ? cnt : cnt - 1);

	return 0;
}
