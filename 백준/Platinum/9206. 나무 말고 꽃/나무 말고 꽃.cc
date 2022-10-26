#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	double V, a, b, h, total = 999999999;
	int N, index = 0;
	cin >> V >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> h;
		double v = b * b * h * h / 2.0;
		double p1 = 0.0, p2 = 0.0;
		double x = 0.00001;
		while (x <= h)
		{
			double dx = x - 0.000005;
			double x2 = dx * dx;
			p1 += 0.00001 * sqrt(dx) * pow(M_E, -x2);
			x += 0.00001;
		}
		x = 0.00001;
		while (x <= h)
		{
			double dx = x - 0.000005;
			double x2 = dx * dx;
			p2 += 0.00001 * pow(M_E, -2*x2);
			x += 0.00001;
		}
		
		p1 *= 2 * a * b;
		p2 *= a * a;
		v += p1;
		v += p2;
		v *= M_PI;

		if (abs(V - v) < total)
		{
			total = abs(V - v);
			index = i;
		}
	}

	cout << index;
	return 0;
}