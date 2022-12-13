#include <iostream>
using namespace std;

int N, K, x, f;

int main(void)
{
	cin >> N >> K;

	x = 1;
	f = 1;
	for (int i = 2; i <= N; i++)
	{
		f = (x + K - 1) % i + 1;
		x = f;
	}

	cout << f;
	return 0;
}