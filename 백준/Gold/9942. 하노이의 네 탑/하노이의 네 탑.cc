#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N, x = 2, cnt = 0, m = 2;
vector <ll> v(1001);

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	v[1] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		if (cnt == m)
		{
			cnt = 0;
			m++;
			x <<= 1;
		}
		cnt++;
		v[i] = v[i - 1] + x;
	}

	cnt = 1;
	while (cin >> N)
		cout << "Case " << cnt++ << ": " << v[N] << '\n';

	return 0;
}