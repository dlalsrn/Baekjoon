#include <bits/stdc++.h>
using namespace std;

string x;
bool m = false;
int i, coef;
string num = "";

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;
	
	if (x[0] == '-') m = true;

	for (i = (m ? 1 : 0); i < x.size() && x[i] != 'x'; i++) num += x[i];

	coef = stoi(num);

	if (coef == 0)
	{
		cout << 'W';
		return 0;
	}

	if (i == x.size())
	{
		if (m) cout << '-';
		if (coef != 1) cout << coef;
		cout << "x+W";
		return 0;
	}

	if (m) cout << '-';
	if (coef / 2 != 1) cout << coef / 2;
	cout << "xx";
	i++;
	if (i == x.size()) cout << "+W";
	else
	{
		cout << x[i++];
		if (i == x.size() - 1 && x[i] == '1') cout << "x+W";
		else
		{
			for (int j = i; j < x.size(); j++) cout << x[j];
			cout << "x+W";
		}
	}

	return 0;
}