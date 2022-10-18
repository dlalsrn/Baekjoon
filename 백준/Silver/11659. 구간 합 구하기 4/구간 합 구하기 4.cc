// 구간 합 구하기 4
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, num;
	int min, max;
	int ary[100001] = { 0 };
	cin >> N >> M;
	for (int i = 1; i < N+1; i++)
	{
		cin >> num;
		ary[i] = ary[i - 1] + num;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> min >> max;
		cout << ary[max] - ary[min -1] << '\n';
	}
	return 0;
}