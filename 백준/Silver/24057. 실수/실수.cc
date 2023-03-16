#include <iostream>
using namespace std;

typedef long long ll;
ll A_A, A_B, A_C, A_D;
ll B_A, B_B, B_C, B_D;
ll ANS_A, ANS_B, ANS_C, ANS_D;
ll x;

ll GCD(ll a, ll b)
{
	ll t;
	while (b)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}
int main(void)
{
	cin >> A_A >> A_B >> A_C >> A_D;
	cin >> B_A >> B_B >> B_C >> B_D;

	ANS_A = A_A * B_A;
	ANS_B = A_B * B_A + B_B * A_A;
	ANS_C = A_C * B_A + B_C * A_A;
	ANS_D = A_D;
	
	x = GCD(GCD(ANS_C, ANS_A), GCD(ANS_B, ANS_A));

	if (x < 0)
		x *= -1;
	if (ANS_C == 0)
		ANS_D = 0;

	if (ANS_A < 0)
		cout << ANS_A / x * -1 << ' ' << ANS_B / x * -1 << ' ' << ANS_C / x * -1 << ' ' << ANS_D << '\n';
	else
		cout << ANS_A / x << ' ' << ANS_B / x << ' ' << ANS_C / x << ' ' << ANS_D << '\n';

	ANS_A = A_A * B_A;
	ANS_B = A_B * B_A - B_B * A_A;
	ANS_C = A_C * B_A - B_C * A_A;
	ANS_D = A_D;

	x = GCD(GCD(ANS_C, ANS_A), GCD(ANS_B, ANS_A));

	if (x < 0)
		x *= -1;
	if (ANS_C == 0)
		ANS_D = 0;

	if (ANS_A < 0)
		cout << ANS_A / x * -1 << ' ' << ANS_B / x * -1 << ' ' << ANS_C / x * -1 << ' ' << ANS_D << '\n';
	else
		cout << ANS_A / x << ' ' << ANS_B / x << ' ' << ANS_C / x << ' ' << ANS_D << '\n';

	ANS_A = A_A * B_A;
	ANS_B = A_B * B_B + A_D * A_C * B_C;
	ANS_C = A_B * B_C + B_B * A_C;
	ANS_D = A_D;

	x = GCD(GCD(ANS_C, ANS_A), GCD(ANS_B, ANS_A));

	if (x < 0)
		x *= -1;
	if (ANS_C == 0)
		ANS_D = 0;

	if (ANS_A < 0)
		cout << ANS_A / x * -1 << ' ' << ANS_B / x * -1 << ' ' << ANS_C / x * -1 << ' ' << ANS_D << '\n';
	else
		cout << ANS_A / x << ' ' << ANS_B / x << ' ' << ANS_C / x << ' ' << ANS_D << '\n';

	ANS_A = A_A * (B_B * B_B - B_C * B_C * B_D);
	ANS_B = B_A * (A_B * B_B + A_C * (-B_C) * A_D);
	ANS_C = B_A * (A_B * (-B_C) + B_B * A_C);
	ANS_D = A_D;

	x = GCD(GCD(ANS_C, ANS_A), GCD(ANS_B, ANS_A));

	if (x < 0)
		x *= -1;
	if (ANS_C == 0)
		ANS_D = 0;

	if (ANS_A < 0)
		cout << ANS_A / x * -1 << ' ' << ANS_B / x * -1 << ' ' << ANS_C / x * -1 << ' ' << ANS_D << '\n';
	else
		cout << ANS_A / x << ' ' << ANS_B / x << ' ' << ANS_C / x << ' ' << ANS_D << '\n';
}