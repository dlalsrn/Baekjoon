#include <stdio.h>

int main(void)
{
	char A[10001];
	char B[10001];
	int TA, TB;
	long long sum = 0;

	scanf("%s %s", &A[0], &B[0]);

	for (int i = 0; A[i] != 0; i++)
	{
		TA = A[i] - 48;
		for (int s = 0; B[s] != 0; s++)
		{
			TB = B[s] - 48;
			sum += TA * TB;
		}
	}

	printf("%lld", sum);

	return 0;
}