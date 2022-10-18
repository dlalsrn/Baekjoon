// 한수
#include <stdio.h>

int main(void)
{
	int cnt = 0, num, seq;
	int N;
	scanf(" %d", &N);

	for (int i = 1; i <= N; i++)
	{
		num = i;
		seq = num % 10 - (num / 10) % 10;
		num /= 10;
		for (; num / 10 != 0; num /= 10)
			if (num % 10 - (num / 10) % 10 != seq)
				break;
		if (num / 10 == 0)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}