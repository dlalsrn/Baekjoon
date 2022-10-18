#include <iostream>
using namespace std;

int main(void)
{
	long long N, M, num, sum = 0, total = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			sum += num;
		}
		total ^= sum;
		sum = 0;
	}
	if (total)
		cout << "august14";
	else
		cout << "ainta";
	return 0;
}