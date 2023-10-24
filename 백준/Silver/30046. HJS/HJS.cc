#include <bits/stdc++.h>
using namespace std;

int N;
string p, q, r;
string x, y, z;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N >> p >> q >> r;

	for (int h = 1; h <= 3; h++) // H
	{
		for (int j = 1; j <= 3; j++) // J
		{
			if (h == j)
				continue;
			for (int s = 1; s <= 3; s++) // S
			{
				if (h == s || j == s)
					continue;
				x = y = z = "";

				for (int i = 0; i < N; i++)
				{
					if (p[i] == 'H')
						x += '0' + h;
					else if (p[i] == 'J')
						x += '0' + j;
					else
						x += '0' + s;
				}
				for (int i = 0; i < N; i++)
				{
					if (q[i] == 'H')
						y += '0' + h;
					else if (q[i] == 'J')
						y += '0' + j;
					else
						y += '0' + s;
				}
				for (int i = 0; i < N; i++)
				{
					if (r[i] == 'H')
						z += '0' + h;
					else if (r[i] == 'J')
						z += '0' + j;
					else
						z += '0' + s;
				}

				if (x < y && y < z)
				{
					cout << "HJS! HJS! HJS!";
					return 0;
				}
			}
		}
	}

	cout << "Hmm...";
	return 0;
}