#include <bits/stdc++.h>
using namespace std;

bool w, b, g;
char x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	w = b = g = false;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cin >> x;
			if (x == 'w')
				w = true;
			else if (x == 'b')
				b = true;
			else if (x == 'g')
				g = true;
		}
	}

	if (w)
		cout << "chunbae";
	else if (b)
		cout << "nabi";
	else if (g)
		cout << "yeongcheol";

	return 0;
}