#include <iostream>
using namespace std;

int last_mn, mx, mn, T, x;

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		mx = 2399, mn = 2100, last_mn = 2100;
		for (int i = 0; i < 4; i++)
		{
			int mid = (mx + mn + 1) / 2;
			cout << "? " << mid << endl;
			cin >> x;

			if (x == 1)
			{
				last_mn = mn;
				mn = mid;
			}
			else
				mx = mid - 1;
		}

		while(mx - mn != 0)
		{
			int mid = (mx + mn + 1) / 2;
			cout << "? " << mid << endl;
			cin >> x;

			if (x == 1)
			{
				last_mn = mn;
				mn = mid;
			}
			else
				mx = mid - 1;
			if (mx - mn == 0)
			{
				cout << "? " << mn << endl;
				cin >> x;
				if (x == 1)
					break;
				else
					mn = last_mn;
			}
		}

		cout << "! " << mn << endl;
	}
}