#include <bits/stdc++.h>
using namespace std;

int a, b;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u') a++;
		if (x[i] == 'y') b++;
	}

	cout << a << ' ' << a + b;

	return 0;
}