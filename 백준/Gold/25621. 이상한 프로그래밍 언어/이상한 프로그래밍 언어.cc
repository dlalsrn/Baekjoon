#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll N, K, x1, x2, mod = 0;
char op1, op2;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> op1 >> x1 >> op2 >> x2;

		if (op1 == '+' && op2 == '+')
		{
			K += max(x1, x2);
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		else if (op1 == '+' && op2 == '-')
		{
			K += x1;
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		else if (op1 == '+' && op2 == '*')
		{
			if (x2 == 0 || x2 == 1)
				K += x1;
			else
			{
				if (mod)
					K *= x2;
				else
					K = max(K + x1, K * x2);
			}
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		else if (op1 == '-' && op2 == '+')
		{
			K += x2;
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		else if (op1 == '-' && op2 == '-')
		{
			K -= min(x1, x2);
			if (K < 0)
			{
				if (mod)
				{
					mod--;
					K += MOD;
				}
				else
					K = 0;
			}
		}
		else if (op1 == '-' && op2 == '*')
		{
			if (x2 == 0)
			{
				K -= x1;
				if (K < 0)
				{
					if (mod)
					{
						mod--;
						K += MOD;
					}
					else
						K = 0;
				}
			}
			else
			{
				K *= x2;
				if (K >= MOD)
				{
					if (mod < MOD)
						mod += K / MOD;
					K %= MOD;
				}
			}
		}
		else if (op1 == '*' && op2 == '+')
		{
			if (x1 == 0 || x1 == 1)
				K += x2;
			else
			{
				if (mod)
					K *= x1;
				else
					K = max(K * x1, K + x2);
			}
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		else if (op1 == '*' && op2 == '-')
		{
			if (x1 == 0)
			{
				K -= x2;
				if (K < 0)
				{
					if (mod)
					{
						mod--;
						K += MOD;
					}
					else
						K = 0;
				}
			}
			else
			{
				K *= x1;
				if (K >= MOD)
				{
					if (mod < MOD)
						mod += K / MOD;
					K %= MOD;
				}
			}
		}
		else if (op1 == '*' && op2 == '*')
		{
			if (x1 == 0 && x2 == 0)
			{
				K = 0;
				mod = 0;
			}
			else if (x1 == 0)
				K *= x2;
			else if (x2 == 0)
				K *= x1;
			else
				K *= max(x1, x2);
			if (K >= MOD)
			{
				if (mod < MOD)
					mod += K / MOD;
				K %= MOD;
			}
		}
		//cout << mod << ' ' << K << '\n';
	}

	cout << K;

	return 0;
}