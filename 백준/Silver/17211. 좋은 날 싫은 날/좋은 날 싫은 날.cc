#include <iostream>
using namespace std;

int main(void)
{
	int N, g;
	cin >> N >> g;
	double a, b, c, d, t1 = 1, t2 = 1, p1, p2;
	cin >> a >> b >> c >> d;
	if (g == 0)
	{
		t1 = a;
		t2 = b;
	}
	else
	{
		t1 = c;
		t2 = d;
	}
	p1 = t1;
	p2 = t2;
	N--;
	while (N--)
	{
		t1 = p1 * a + p2 * c;
		t2 = p1 * b + p2 * d;
		p1 = t1;
		p2 = t2;
	}
	printf("%.0lf\n%.0lf", t1 * 1000, t2 * 1000);
	return 0;
}