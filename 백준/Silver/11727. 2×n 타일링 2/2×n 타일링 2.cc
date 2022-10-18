// 2 x n 타일링 2
#include <iostream>
using namespace std;

int main(void)
{
	int n, sum;
	int tile[1001];
	tile[1] = 1;
	sum = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			tile[i] = sum + 2;
		else
			tile[i] = sum + 1;
		sum += tile[i];
		sum %= 10007;
	}
	cout << tile[n] << '\n';
	return 0;
}