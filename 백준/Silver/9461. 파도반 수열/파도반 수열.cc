#include <iostream>
using namespace std;

long long pado(int n)
{
	long long ary[101];
	ary[1] = 1;
	ary[2] = 1;
	ary[3] = 1;
	ary[4] = 2;
	ary[5] = 2;
	for (int i = 6; i < n+1; i++)
		ary[i] = ary[i - 1] + ary[i - 5];
	return ary[n];
}

int main(void)
{
	int T;
	long long n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << pado(n) << '\n';
	}
	return 0;
}