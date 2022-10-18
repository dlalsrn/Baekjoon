#include <iostream>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	if (N == 1)
		cout << 1;
	else
	{
		int max = 7, plus = 12;
		int cnt = 2;
		while (N > max)
		{
			max += plus;
			plus += 6;
			cnt++;
		}
		cout << cnt;
	}
	return 0;
}