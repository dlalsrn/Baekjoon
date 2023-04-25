#include <iostream>
#include <vector>
using namespace std;

int N;
long long sum = 0;
vector <bool> v(1000001, true);

int main(void)
{
	cin >> N;
	
	for (int i = 2; i * i <= 1000000; i++)
		if (v[i])
			for (int j = i * i; j <= 1000000; j += i)
				v[j] = false;

	for (int i = 2; i <= N; i++)
	{
		if (v[i])
			sum += i;
		else
		{
			int j = 2;
			while (i % j)
				j++;
			sum += j;
		}
	}

	cout << sum << '\n';

	return 0;
}