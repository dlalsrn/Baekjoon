#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	set <long long> s;
	long long N;
	double temp;
	cin >> N;
	temp = N;
	long long i = 2;
	while (i * i <= N)
	{
		
		if (N % i == 0)
		{
			s.insert(i);
			N /= i;
		}
		else
			i++;
	}
	if (N != 1)
		s.insert(N);
	for (auto it = s.begin(); it != s.end(); it++)
		temp *= (1 - ((double)1 / (*it)));
	printf("%.0lf\n", temp);
	return 0;
}