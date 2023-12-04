#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a, b;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	while (cin >> a)
	{
		cin >> b;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 'i')
				cout << 'e';
			else if (a[i] == 'e')
				cout << 'i';
			else if (a[i] == 'I')
				cout << 'E';
			else if (a[i] == 'E')
				cout << 'I';
			else
				cout << a[i];
		}
		cout << ' ';
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == 'i')
				cout << 'e';
			else if (b[i] == 'e')
				cout << 'i';
			else if (b[i] == 'I')
				cout << 'E';
			else if (b[i] == 'E')
				cout << 'I';
			else
				cout << b[i];
		}
		cout << '\n';
	}

	return 0;
}