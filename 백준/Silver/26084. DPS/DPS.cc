#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

string s, x;
ll N;
vector <ll> X(26, 0);
vector <ll> S(26, 0);
ll U = 1, D = 1;

ll fac(ll n)
{
	for (ll i = n - 1; i > 1; i--)
		n *= i;
	return n;
}

int main(void)
{
	cin >> s >> N;

	for (ll i = 0; i < s.length(); i++)
		S[s[i] - 65]++;

	for (ll i = 0; i < 26; i++)
		if (S[i])
			D *= fac(S[i]);

	for (ll i = 0; i < N; i++)
	{
		cin >> x;
		X[x[0] - 65]++;
	}

	for (ll i = 0; i < s.length(); i++)
		U *= X[s[i] - 65]--;
	cout << U / D;
	return 0;
}