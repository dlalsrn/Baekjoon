#include <iostream>
using namespace std;

int last_mn, last_mx, mx, mn, T, x;
bool check = true;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		mx = 2399, mn = 2100, last_mn = 2100, last_mx = 2399, check = true;

		while(mx - mn != 0)
		{
			int mid = (mx + mn + 1) / 2;
			cout << "? " << mid << endl;
			cin >> x;

			if (x == 1)
			{
				last_mn = mn;
				last_mx = mn = mid;
			}
			else
				mx = mid - 1;

			if (mx - mn == 0 && check)
			{
				cout << "? " << mn << endl;
				cin >> x;
				if (x == 1)
					break;
				else
				{
					check = false;
					mn = last_mn;
					mx = last_mx - 1;
				}
			}
		}

		cout << "! " << mn << endl;
	}
}