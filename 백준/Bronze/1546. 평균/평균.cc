// 평균
#include <stdio.h>

int main(void)
{
	float score[1000];
	int n;
	float max = 0, result = 0;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %f", &score[i]);
		if (max < score[i])
			max = score[i];
	}
	for (int i = 0; i < n; i++)
	{
		score[i] = score[i] / max * 100;
		result += score[i];
	}
	printf("%f", result / n);
	return 0;
}