#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, num;
	int ary[10001] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		ary[num]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = 0; j < ary[i]; j++)
				cout << i << '\n';
		}
	}
	return 0;
}