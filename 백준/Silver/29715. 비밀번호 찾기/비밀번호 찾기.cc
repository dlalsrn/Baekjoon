#include <iostream>
using namespace std;
using ll = long long;

ll N, M, X, Y, a, b, cnt1 = 1, cnt2 = 1, t = 1, ans = 0;
ll correct_num = 0, random_num = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> X >> Y;

	for (ll i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (a)
			correct_num++;
		else
			random_num++;
	}

	for (ll i = 9 - (correct_num + random_num); i > 9 - N; i--)
		cnt1 *= i;
	for (ll i = N - correct_num; i > random_num; i--)
		cnt2 *= i;
	for (ll i = random_num; i > 0; i--)
		cnt2 *= i;
	for (ll i = N - correct_num - random_num; i > 0; i--)
		t *= i;

	cnt2 /= t;

	cnt1 *= cnt2;

	if (cnt1 % 3)
		ans += Y * (cnt1 / 3);
	else
		ans += Y * (cnt1 / 3 - 1);

	ans += cnt1 * X;

	cout << ans;

	return 0;
}