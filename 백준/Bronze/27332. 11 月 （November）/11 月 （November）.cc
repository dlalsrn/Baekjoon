#include <bits/stdc++.h>
using namespace std;

int a, b, days;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> a >> b;

	days = a + 7 * b;

	if (days >= 1 && days <= 30) cout << "1\n";
	else cout << "0\n";

	return 0;
}