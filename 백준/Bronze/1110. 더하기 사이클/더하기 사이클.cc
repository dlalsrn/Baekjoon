#include <stdio.h>

int main(void)
{
	int first, mid, last = 0;
	int cnt = 0;
	scanf(" %d", &first);
	mid = first;

	while (1)
	{
		last = (mid / 10) + (mid % 10);
		cnt++;
		last = (mid % 10) * 10 + (last % 10);
		if (first == last)
			break;
		mid = last;
	}
	printf("%d \n", cnt);
	return 0;
}