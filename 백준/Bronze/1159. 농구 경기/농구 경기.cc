#include <stdio.h>

int main(void)
{
	int N, count = 0;
	char name[30];
	int alpha[26] = { 0 };

	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %s", &name[0]);
		alpha[(int)name[0] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] >= 5)
		{
			printf("%c", (i+97));
			count++;
		}
	}
	
	if (count == 0)
		printf("PREDAJA");

	return 0;
}