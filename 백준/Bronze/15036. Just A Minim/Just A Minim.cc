#include <iostream>
#include <map>
using namespace std;

int N, c;
double ans = 0;
map <int, double> m;

int main(void)
{
	cin >> N;

	m[0] = 2.0;
	m[1] = 1.0;
	m[2] = 1.0 / 2.0;
	m[4] = 1.0 / 4.0;
	m[8] = 1.0 / 8.0;
	m[16] = 1.0 / 16.0;

	for (int i = 0; i < N; i++)
	{
		cin >> c;
		ans += m[c];
	}
	
	printf("%lf", ans);

	return 0;
}