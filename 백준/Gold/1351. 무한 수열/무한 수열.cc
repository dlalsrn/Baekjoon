#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
map <ll, ll> m;
ll N, P, Q;

ll sum(ll n)
{
	return (m[n] ? m[n] : m[n] = sum(n / P) + sum(n / Q));
}

int main(void)
{
	cin >> N >> P >> Q;
	m[0] = 1;
	cout << sum(N);
	return 0;
}