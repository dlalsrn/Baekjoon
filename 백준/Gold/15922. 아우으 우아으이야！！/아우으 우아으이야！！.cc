#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, x, y, cnt = 0, temp;
	int sum = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (i == 0)
		{
			sum += y - x;
			temp = y;
		}
		else
		{
			if (temp >= x)
			{
				if (temp < y)
				{
					sum += y - temp;
					temp = y;
				}
			}
			else
			{
				sum += y - x;
				temp = y;
			}
		}
	}
	
	cout << sum << endl;
	return 0;
}