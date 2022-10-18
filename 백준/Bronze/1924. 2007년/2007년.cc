#include <stdio.h>

int main(void)
{
	int x, y;
	int Day = 1;

	scanf(" %d %d", &x, &y);

	for (int i = 1; i < x; i++)
	{
		if (i != x)
		{
			if (i == 4 || i == 6 || i == 9 || i == 11)
				Day += 30;
			else if (i == 2)
				Day += 28;
			else
				Day += 31;
		}
	}

	Day += (y-1);
	Day = Day % 7;

	if (Day == 1)
		printf("MON");
	else if (Day == 2)
		printf("TUE");
	else if (Day == 3)
		printf("WED");
	else if (Day == 4)
		printf("THU");
	else if (Day == 5)
		printf("FRI");
	else if (Day == 6)
		printf("SAT");
	else if (Day == 0)
		printf("SUN");

	return 0;
}