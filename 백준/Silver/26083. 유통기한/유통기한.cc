#include <iostream>
using namespace std;

int N, Y, M, D, A, B, C, cnt;
bool TF;

void X(int A, int B, int C)
{
	int yun = (A % 4 ? 0 : 1);
	int m = (B == 1 || B == 3 || B == 5 || B == 7 || B == 8 || B == 10 || B == 12 ? 1 : 0);
	if (1 <= B && B <= 12)
	{
		if (B == 2)
		{
			if (1 <= C && C <= 28 + yun)
			{
				if (Y > A)
					TF = false;
				else if (Y == A)
				{
					if (M > B)
						TF = false;
					else if (M == B)
					{
						if (D > C)
							TF = false;
					}
				}
			}
			else
				cnt++;
		}
		else
		{
			if (1 <= C && C <= 30 + m)
			{
				if (Y > A)
					TF = false;
				else if (Y == A)
				{
					if (M > B)
						TF = false;
					else if (M == B)
					{
						if (D > C)
							TF = false;
					}
				}
			}
			else
				cnt++;
		}
	}
	else
		cnt++;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> Y >> M >> D;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;

		TF = true;
		cnt = 0;

		// Y/M/D 인 경우
		X(A, B, C);

		// D/M/Y 인 경우
		X(C, B, A);

		// M/D/Y 인 경우
		X(C, A, B);

		if (cnt == 3)
			cout << "invalid\n";
		else if (TF)
			cout << "safe\n";
		else
			cout << "unsafe\n";
	}
	return 0;
}