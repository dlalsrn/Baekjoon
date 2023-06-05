#include <iostream>
#include <cmath>
using namespace std;

int N, x;

int main(void)
{
	cin >> x >> N;

	for (int i = 0; i < N; i++)
	{
		if (x % 2)
			x = (x * 2) ^ 6;
		else
			x = (x / 2) ^ 6;
	}

	cout << x;

	return 0;
}