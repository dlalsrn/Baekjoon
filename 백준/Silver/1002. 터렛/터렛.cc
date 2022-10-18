#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
	int x1, y1, r1, x2, y2, r2, N;
    double d;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
		d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1" << '\n';
		else if (r1 + r2 == d || d + r1 == r2 || d + r2 == r1)
			cout << "1" << '\n';
		else if (r1 + r2 > d && d + r1 > r2 && d + r2 > r1)
			cout << "2" << '\n';
		else
			cout << "0" << '\n';
	}
    return 0;
}