#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> a >> b;

	b -= a;

	if (b <= 0)
		cout << "Congratulations, you are within the speed limit!";
	else if (b <= 20)
		cout << "You are speeding and your fine is $" << 100 << ".\n";
	else if (b <= 30)
		cout << "You are speeding and your fine is $" << 270 << ".\n";
	else
		cout << "You are speeding and your fine is $" << 500 << ".\n";

	return 0;
}