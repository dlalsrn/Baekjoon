#include <stdio.h>

int main(void)
{
	int n, d;
	int cnt = 0;

	scanf(" %d %d", &n, &d);

	for (int i = 1; i <= n; i++)
	{
		int c = i;
		while (c)
		{
			if (c % 10 == d)
			{
				cnt += 1;
			}
			c /= 10;
		}
	}

	printf("%d", cnt);

	return 0;
}