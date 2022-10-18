#include <stdio.h>

int main(void)
{
	int N, num;
	int count = 0;

	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &num);
		for (int s = 2; s <= num; s++)
		{
			if (s == num)
				count++;
			else if (num%s == 0)
				break;
		}
	}

	printf("%d", count);

	return 0;
}