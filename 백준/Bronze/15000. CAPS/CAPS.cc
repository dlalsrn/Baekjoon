#include <bits/stdc++.h>
using namespace std;

string x;

int main(void)
{
	cin >> x;

	transform(x.begin(), x.end(), x.begin(), ::toupper);
	cout << x;

	return 0;
}