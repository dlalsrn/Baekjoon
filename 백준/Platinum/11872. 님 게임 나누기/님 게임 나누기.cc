#include <iostream>
using namespace std;

int main(void)
{
	long long N, sum = 0, num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num % 4 == 0)
			sum ^= num - 1;
		else if (num % 4 == 3)
			sum ^= num + 1;
		else
			sum ^= num;
	}
	if (sum)
		cout << "koosaga";
	else
		cout << "cubelover";
	return 0;
}