// 님 게임 홀짝
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long N, num, sum = 0, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num % 2 == 1)
			sum ^= (num + 1) / 2;
		else
			sum ^= (num - 2) / 2;
	}

	if (sum)
		cout << "koosaga";
	else
		cout << "cubelover";
	return 0;
}