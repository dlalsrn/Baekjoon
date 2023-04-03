#include <iostream>
using namespace std;

long long N, x = 1, ans = 0;

int main(void)
{
	cin >> N;

	while (N >= x * x)
	{
		N -= x * x;
		x++;
		ans++;
	}
	cout << ans;
	return 0;
}