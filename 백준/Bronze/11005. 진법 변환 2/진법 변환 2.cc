#include <iostream>
#include <string>
using namespace std;

long long N, B, T, x;
string ans = "";

int main(void)
{

	cin >> N >> B;

	T = 1;

	while (T * B <= N)
		T *= B;

	while (N)
	{
		x = N / T;
		if (x < 10)
			ans += to_string(x);
		else
		{
			x -= 10;
			char a = (char)('A' + x);
			ans += a;
		}
		N %= T;
		T /= B;
	}

	while (T)
	{
		ans += "0";
		T /= B;
	}

	cout << ans;

	return 0;
}