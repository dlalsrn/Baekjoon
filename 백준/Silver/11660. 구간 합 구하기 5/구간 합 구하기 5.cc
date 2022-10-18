// 구간 합 구하기 5
#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, num, sum;
	int x1, x2, y1, y2;
	int ary[1025][1025] = { 0 };
	int ori[1025][1025] = { 0 };
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> num;
			ori[i][j] = num;
			if (j == 1)
				ary[i][j] = ary[i - 1][N] + num;
			else
				ary[i][j] = ary[i][j - 1] + num;
		}
	}

	for (int i = 0; i < M; i++)
	{
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			if (y1 - 1 == 0)
				sum = ary[x2][y2] - ary[x1 - 1][N];
			else
				sum = ary[x2][y2] - ary[x1][y1 - 1];
		}
		else
		{
			for (int j = x1; j <= x2; j++)
			{
				if (y1 - 1 == 0)
					sum += ary[j][y2] - ary[j - 1][N];
				else
					sum += ary[j][y2] - ary[j][y1 - 1];
			}
		}
		cout << sum << '\n';
	}
	
	return 0;
}