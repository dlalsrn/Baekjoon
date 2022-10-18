// 소수 구하기
#include <iostream>
using namespace std;

int main(void)
{
	int min, max;
	cin >> min >> max;
	char TF[1000000] = { 0 };
	TF[1] = 1;
	for (int i = 2; i * i <= max; i++)
	{
		if (!TF[i])
		{
			for (int j = i * i; j <= max; j += i)
				TF[j]++;
		}
	}
	for (int i = min; i <= max; i++)
	{
		if (!TF[i])
			printf("%d\n", i);
	}
	return 0;
}