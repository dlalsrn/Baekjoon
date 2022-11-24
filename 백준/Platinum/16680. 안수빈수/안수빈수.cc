#include <iostream>
using namespace std;
typedef long long ll;

ll T, N, cnt, temp;

ll search(ll n)
{
	ll x = 0;
	while (n)
	{
		if (n % 2)
			x++;
		n /= 10;
	}
	return x;
}

int main(void)
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		temp = N;

		if (!(search(temp) % 2))
		{
			for (temp = N * 2; (!(search(temp) % 2)) && temp <= 1000000000000000000; temp *= 2);
			
			if (temp > 1000000000000000000)
				for (temp = N * 3; (!(search(temp) % 2)) && temp <= 1000000000000000000; temp *= 3);
		}

		cout << temp << '\n';
	}

	return 0;
}