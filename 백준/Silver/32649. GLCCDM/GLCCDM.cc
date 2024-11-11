#include <bits/stdc++.h>
using namespace std;

int A, B, K;
vector <int> v;

int gcd(int a, int b)
{
	if (!b) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> A >> B >> K;

	for (int i = A; i <= B; i += A)
		if (!(B % i)) v.push_back(i);

	if (v.size() < K) cout << -1;
	else
	{
		for (int i = 0; i < K - 1; i++) cout << v[i] << ' ';
		cout << B;
	}

	return 0;
}