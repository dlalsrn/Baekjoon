#include <stdio.h>

int main(void)
{
	int M, N;
	int U, L, R, D;
	char P[10][11] = { 0 };

	scanf("%d %d", &M, &N);
	scanf("%d %d %d %d", &U, &L, &R, &D);

	for (int i = 0; i < M; i++)
		scanf("%s", &P[i][0]);

	for (int i = 1; i <= M + U + D; i++)
	{
		if (i > U && i <= U+M)
		{
			for (int s = 1; s <= L; s++)
			{
				if ((s+i) % 2 == 0)
					printf("#");
				else
					printf(".");
			}
			for (int k = 0; k < N; k++)
				printf("%c", P[i-U-1][k]);
			for (int s = 1; s <= R; s++)
			{
				if ((s+i+N+L) % 2 == 0)
					printf("#");
				else
					printf(".");
			}
			printf("\n");
		}
		else
		{
			for (int s = 1; s <= N + R + L; s++)
			{
				if ((s+i) % 2 == 0)
					printf("#");
				else
					printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}