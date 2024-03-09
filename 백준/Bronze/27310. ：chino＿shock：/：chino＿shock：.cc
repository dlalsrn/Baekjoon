#include <bits/stdc++.h>
using namespace std;

int c, u;
string x;

int main(void)
{
	cin >> x;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '_') u++;
		else if (x[i] == ':') c++;
	}

	cout << x.size() + c + u * 5;

	return 0;
}