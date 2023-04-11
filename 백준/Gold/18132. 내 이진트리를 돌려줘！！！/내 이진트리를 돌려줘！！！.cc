#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll T, E;
vector <ll> v(5002, 0);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	v[0] = 1;

	for (int i = 1; i < 5002; i++)
		for (int j = 0; j < i; j++)
			v[i] = (v[i] + v[j] * v[i - j - 1]) % MOD;

	for (int i = 0; i < T; i++)
	{
		cin >> E;
		cout << v[E + 1] << '\n';
	}

	return 0;
}