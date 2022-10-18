#include <iostream>
using namespace std;

int main(void)
{
	float x, y, w, h;
	cin >> x >> y >> w >> h;

	if (x >= w/2)
	{
		if (y >= h / 2)
			cout << ((h - y > w - x) ? w - x : h - y);
		else
			cout << ((y > w - x) ? w - x : y);
	}
	else
	{
		if (y >= h/2)
			cout << ((h - y > x) ? x : h - y);
		else
			cout << ((y > x) ? x : y);
	}
	return 0;
}