// 셀프 넘버
#include <stdio.h>

int main(void)
{
	int sum, num;
	int ary[10001] = { 0 };
	for (int i = 1; i <= 10000; i++)
	{
		sum = i;
		while (sum <= 10000)
		{
			ary[sum]++;
			num = sum;
			for (; num; num /= 10)
				sum += num % 10;
		}
	}

	for (int i = 1; i <= 10000; i++)
		if (ary[i] == 1)
			printf("%d\n", i);
	return 0;
}