#include <iostream>
#include <vector>
using namespace std;
vector <bool> number;
vector <int> prime;
int N, cnt = 0, sum;

int main(void)
{
	cin >> N;
	number = vector<bool>(N + 1, false);

	for (int i = 2; i * i <= N; i++)
		if (!number[i])
			for (int j = i * i; j <= N; j += i)
				number[j] = true;

	for (int i = 2; i <= N; i++)
		if (!number[i])
			prime.push_back(i);

	int i = 0, j = 0;
	while (i < prime.size())
	{
		if (sum < N)
		{
			if (j == prime.size())
				break;
			sum += prime[j++];
		}
		else if (sum > N)
			sum -= prime[i++];
		else
		{
			cnt++;
			if (j == prime.size())
				break;
			sum += prime[j++];
			sum -= prime[i++];
		}
	}

	cout << cnt;
	return 0;
}