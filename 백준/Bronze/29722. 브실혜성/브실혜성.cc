#include <iostream>
using namespace std;

int y, m, d, N;
char x;

int main(void)
{
	cin >> y >> x >> m >> x >> d >> N;

	d += (N % 30);
	if (d > 30)
	{
		m++;
		d -= 30;
	}
	m += (N % 360) / 30;
	if (m > 12)
	{
		y++;
		m -= 12;
	}
	y += N / 360;

	cout << y << '-';
	if (m < 10)
		cout << '0';
	cout << m << '-';
	if (d < 10)
		cout << '0';
	cout << d;

	return 0;
}