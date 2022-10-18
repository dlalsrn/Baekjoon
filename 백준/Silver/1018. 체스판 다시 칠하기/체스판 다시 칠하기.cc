#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	priority_queue <int, vector<int>, greater<int>> q;
	int N, M, cnt;
	char check;
	char chess[51][51];
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> chess[i];

	for (int i = 0; i <= N-8; i++)
	{
		for (int j = 0; j <= M-8; j++)
		{
			for (int g = 0; g < 4; g++)
			{
				cnt = 0;
				if (g == 0)
					check = chess[i][j];
				else if (g == 1)
				{
					check = chess[i][j + 7];
					if (check == 'B')
						check = 'W';
					else
						check = 'B';
				}
				else if (g == 2)
				{
					check = chess[i + 7][j];
					if (check == 'B')
						check = 'W';
					else
						check = 'B';
				}
				else
					check = chess[i + 7][j + 7];
				for (int k = 0; k < 8; k++)
				{
					for (int h = 0; h < 8; h++)
					{
						if (k % 2 == 0)
						{
							if (h % 2 == 0)
							{
								if (chess[k + i][h + j] != check)
									cnt++;
							}
							else
								if (chess[k + i][h + j] == check)
									cnt++;
						}
						else
						{
							if (h % 2 == 0)
							{
								if (chess[k + i][h + j] == check)
									cnt++;
							}
							else
								if (chess[k + i][h + j] != check)
									cnt++;
						}
					}
				}
				q.push(cnt);
			}
		}
	}
	cout << q.top();
	return 0;
}