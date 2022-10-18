#include <stdio.h>

int main(void)
{
	int N;
	int count = 0;
	int score[100] = { 0 };

	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
		scanf(" %d", &score[i]);

	for (int i = N-2; i >= 0 ; i--)
		for (; score[i] >= score[i + 1]; score[i]--)
			count++;

	printf("%d", count);

	return 0;
}