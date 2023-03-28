#include <iostream>
#include <string>
#include <map>
using namespace std;

string x;
map <char, char> m;

int main(void)
{
	string t = "AHIMOTUVWXY18";

	for (char a : t)
		m[a] = a;
	m['E'] = '3';
	m['J'] = 'L';
	m['L'] = 'J';
	m['S'] = '2';
	m['Z'] = '5';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';


	while (cin >> x)
	{
		int pal = 0;
		int mir = 0;
		for (int i = 0; i < x.size() / 2; i++)
		{
			if (x[i] == x[x.size() - 1 - i] && m[x[i]] == x[x.size() - 1 - i] && m[x[x.size() - 1 - i]] == m[x[i]])
			{
				pal++;
				mir++;
			}
			else if (m[x[i]] == x[x.size() - 1 - i] && m[x[x.size() - 1 - i]] == x[i])
				mir++;
			else if (x[i] == x[x.size() - 1 - i])
				pal++;
		}
		if ((pal == x.size() / 2 && mir == x.size() / 2 && pal != 0 && mir != 0) || x.size() == 1 && m[x[0]] == x[0])
			cout << x << " -- is a mirrored palindrome.\n\n";
		else if (x.size() == 1 || pal == x.size() / 2)
			cout << x << " -- is a palindrome.\n\n";
		else if (mir == x.size() / 2)
			cout << x << " -- is a mirrored string.\n\n";
		else
			cout << x << " -- is not a palindrome.\n\n";
	}

	return 0;
}