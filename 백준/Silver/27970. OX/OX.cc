#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector <ll> s(100000);
string x;
ll sum = 0;

int main(void)
{
	cin >> x;

	s[0] = 0;

	for (ll i = 1; i < 100000; i++)
		s[i] = (s[i - 1] * 2 + 1) % MOD;

	for (int i = 0; i < x.size(); i++)
		if (x[i] == 'O')
			sum = (sum + s[i] + 1) % MOD;

	cout << sum;

	return 0;
}