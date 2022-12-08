#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
map <ll, ll> m;
ll N, P, Q;

ll sum(ll n)
{
	if (n == 0)
		return 1;
	else if (m[n])
		return m[n];
	m[n] = sum(n / P) + sum(n / Q);
	return m[n];
}

int main(void)
{
	cin >> N >> P >> Q;
	cout << sum(N);
	return 0;
}