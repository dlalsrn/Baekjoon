#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int Q, x;
vector<ll> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> Q;

	v = vector<ll>(10000000, 0);
	v[0] = 4;

	for (int i = 1; i < v.size(); ++i)
	{
		v[i] = v[i - 1] * 5;
		v[i] %= 1000000007;
	}

	for (int i = 0; i < Q; ++i)
	{
		cin >> x;
		if (x == 1)
		{
			cout << 5 << '\n';
		}
		else
		{
			cout << v[x - 1] << '\n';
		}
	}

	return 0;
}