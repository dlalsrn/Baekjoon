#include <iostream>
using namespace std;
int N, cnt = 0;

int fibo(int n)
{
	if (n == 1 || n == 2)
	{
		cnt++;
		return 1;
	}
	else
		return fibo(n - 1) + fibo(n - 2);
}
int main(void)
{
	cin >> N;
	fibo(N);
	cout << cnt << ' ' << N - 2;
	return 0;
}