// 완전한 수열
// 22.11.27
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector <ll> sosu;
vector <ll> v(1000001, 0);
vector <ll> ary;
ll N, cnt = 0;

void SS()
{
	for (ll i = 2; i <= 1000000; i++)
	{
		if (v[i])
			continue;
		sosu.push_back(i);
		for (ll j = i * i; j <= 1000000; j += i)
			v[j]++;
	}
}

int main(void)
{
	cin >> N;

	ary.resize(N + 1, 0);
	SS();
	v[0] = v[1] = 1;
	for (ll i = 1; i <= N; i++)
	{
		cin >> ary[i];
		ary[i] += ary[i - 1];
	}

	for (ll i = 0; i < sosu.size(); i++)
	{
		ll r = sosu[i];
		ll l = 1;
		if (r > N)
			break;
		for (ll l = 1, r = sosu[i]; r <= N; r++, l++)
			if (!(v[ary[r] - ary[l - 1]]))
				cnt++;
	}

	cout << cnt;

	return 0;
}