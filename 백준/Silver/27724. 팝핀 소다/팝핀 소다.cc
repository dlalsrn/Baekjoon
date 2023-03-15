#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, K;

int main(void)
{
	cin >> N >> M >> K;
	int a = N / 2; // 절반의 수
	int win = log2(a); // 절반에서 최대로 이기는 수

	if (N == K)
		cout << log2(N);
	else
	{
		while (K < a)
		{
			a = a / 2;
			win = log2(a);
		}

		cout << (win + M > log2(N) ? log2(N) : win + M);
	}

	return 0;
}