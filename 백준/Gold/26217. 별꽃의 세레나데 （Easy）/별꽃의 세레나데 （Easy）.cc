#include <stdio.h>

int main() {
	int N;
	double s = 0.;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)	s += ((double)N / i);
	printf("%.6f", s);
}