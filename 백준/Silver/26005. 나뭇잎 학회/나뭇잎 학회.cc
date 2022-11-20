#include <iostream>
using namespace std;

int N;

int main(void)
{
	cin >> N;
	cout << (N == 1 ? 0 : (N * N % 2 == 0 ? N * N / 2 : N * N / 2 + 1));
	return 0;
}