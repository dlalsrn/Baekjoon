#include <iostream>
using namespace std;

bool gcd(long long a, long long b)
{
	long long temp;
	while (a % b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	if (b == 1)
		return true;
	else
		return false;
}

int main(void)
{
	long long a, b, q, temp, N;
	long long r0, r1, s0, s1, t0, t1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (gcd(a, b))
		{
			if (a == 1)
			{
				if (b == 1)
					cout << 2 << '\n';
				else
					cout << 1 << '\n';
				continue;
			}
			else if (b == 1)
			{
				if (a + 1 > 1e+9)
					cout << "IMPOSSIBLE\n";
				else
					cout << a + 1 << '\n';
				continue;
			}
			r0 = a; r1 = b; s0 = 1, s1 = 0; t0 = 0; t1 = 1;
			while (true)
			{
				q = r0 / r1;
				temp = r0;
				r0 = r1;
				r1 = temp - r1 * q;
				if (r1 == 0)
					break;
				temp = s0;
				s0 = s1;
				s1 = temp - s1 * q;
				temp = t0;
				t0 = t1;
				t1 = temp - t1 * q;
			}
			if (t1 < 0)
			{
				if (a + t1 > 1e+9)
					cout << "IMPOSSIBLE\n";
				else
					cout << a + t1 << '\n';
			}
			else
			{
				if (t1 > 1e+9)
					cout << "IMPOSSIBLE\n";
				else
					cout << t1 << '\n';
			}
		}
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}