#include <iostream>
#include <vector>
using namespace std;

int N, cnt = 0;
string x;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		for (int j = 0; j < x.size() - 1; j++)
		{
			if (x[j] == '0' && x[j + 1] == '1')
			{
				cnt++;
				break;
			}
			if (x[j] == 'O' && x[j + 1] == 'I')
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}