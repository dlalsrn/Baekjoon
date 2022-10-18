#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
	int T, n;
	cin >> T;
	int N[41][2] = { 0 };
	N[0][0] = 1;
	N[1][1] = 1;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		if (n == 0)
			cout << N[0][0] << " " << N[0][1] << '\n';
		else if (n == 1)
			cout << N[1][0] << " " << N[1][1] << '\n';
		else
		{
			for (int i = 2; i < n + 1; i++)
			{
				N[i][0] = N[i - 1][0] + N[i - 2][0];
				N[i][1] = N[i - 1][1] + N[i - 2][1];
			}
			cout << N[n][0] << " " << N[n][1] << '\n';
		}
	}
    return 0;
}