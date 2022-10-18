#include <iostream>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	M -= N;
	long long sum = 1, t = 1;
	for (int i = M + N - 1; i > M; i--)
		sum *= i;
	for (int i = N-1; i >= 1; i--)
		t *= i;

	cout << sum/t;
	return 0;
}