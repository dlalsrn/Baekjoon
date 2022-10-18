#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	int X, Y, D, T;
	cin >> X >> Y >> D >> T;
	double distance = sqrt(X * X + Y * Y);
	double second = 0;
	if (D < distance)
	{
		double jump = (int)(distance / D);
		printf("%.9lf", min(min((jump+1) * T, distance), jump*T + (distance-jump*D)));
	}
	else if (D > distance)
	{
		printf("%.9lf", min(min((double)T * 2, distance), (double)T + ((double)D - distance)));
	}
	else
	{
		if (T >= distance)
			printf("%.9lf", distance);
		else
			printf("%.9lf", (double)T);
	}
	return 0;
}