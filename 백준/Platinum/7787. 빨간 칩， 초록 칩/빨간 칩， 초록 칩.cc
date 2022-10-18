#include <iostream>
using namespace std;

int main(void)
{
	int r, g, sum = 0;
	cin >> r >> g;
	if (r % 2 == 1)
		sum ^= 1;
	else
	{
		int cnt = 0;
		while (r % 2 == 0)
		{
			cnt++;
			r /= 2;
		}
		sum ^= cnt + 1;
	}

	if (g % 2 == 1)
		sum ^= 1;
	else
	{
		int cnt = 0;
		while (g % 2 == 0)
		{
			cnt++;
			g /= 2;
		}
		sum ^= cnt + 1;
	}
	if (sum)
		cout << "A player wins";
	else
		cout << "B player wins";
	return 0;
}