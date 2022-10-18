#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, K, coin, cnt = 0, sum = 0;
	vector <int> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> coin;
		v.push_back(coin);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (v[i] <= K)
		{
			cnt += (K / v[i]);
			K -= v[i] * (K / v[i]);
		}
		if (K == 0)
			break;
	}
	cout << cnt;
	return 0;
}