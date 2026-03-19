#include <iostream>
#include <algorithm>
using namespace std;

int N;
double cur = 1.0;
double mx = 0;
double t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> t;

		if (cur * t < t)
		{
			cur = 1.0;
		}

		cur *= t;
		mx = max(mx, cur);
	}
	
	cout << fixed;
	cout.precision(3);
	cout << mx << '\n';

	return 0;
}