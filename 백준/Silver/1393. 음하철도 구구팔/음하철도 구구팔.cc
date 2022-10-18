#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int xs, ys, x, y, dx, dy, slope, pre_x, pre_y;
	double min = 10000, distance;
	cin >> xs >> ys;
	cin >> x >> y >> dx >> dy;

	if (dx == 0)
	{
		while (true)
		{
			distance = sqrt((xs - x) * (xs - x) + (ys - y) * (ys - y));
			if (min <= distance)
				break;
			min = distance;
			pre_x = x;
			pre_y = y;
			y += dy;
		}
	}
	else if (dy % dx == 0)
	{
		slope = dy / dx;
		while (true)
		{
			distance = sqrt((xs - x) * (xs - x) + (ys - y) * (ys - y));
			if (min <= distance)
				break;
			min = distance;
			pre_x = x;
			pre_y = y;
			x += 1;
			y += slope;
		}
	}
	else
	{
		while (true)
		{
			distance = sqrt((xs - x) * (xs - x) + (ys - y) * (ys - y));
			if (min <= distance)
				break;
			min = distance;
			pre_x = x;
			pre_y = y;
			x += dx;
			y += dy;
		}
	}
	cout << pre_x << ' ' << pre_y;
	return 0;
}