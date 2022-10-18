// 2 x n 타일링
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int tile[1001];
	tile[1] = 1;
	tile[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++)
		tile[i] = (tile[i - 1] + tile[i - 2])%10007;
	cout << tile[n];
	return 0;
}