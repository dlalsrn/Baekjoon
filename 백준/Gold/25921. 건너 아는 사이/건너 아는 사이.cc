#include <iostream>
#include <vector>
using namespace std;

int N;
long long sum = 0;
vector <int> v(1000001, 0);

int main(void)
{
	cin >> N;
	
	for (int i = 2; i * i <= 1000000; i++)
		if (!v[i])
			for (int j = i * i; j <= 1000000; j += i)
				if (!v[j])
					v[j] = i;

	for (int i = 2; i <= N; i++)
		sum += (v[i] ? v[i] : i);

	cout << sum << '\n';

	return 0;
}