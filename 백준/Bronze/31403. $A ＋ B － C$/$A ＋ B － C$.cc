#include <bits/stdc++.h>
using namespace std;

string a, b;
int c;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b >> c;

	cout << stoi(a) + stoi(b) - c << '\n';

	a += b;

	cout << stoi(a) - c;

	return 0;
}