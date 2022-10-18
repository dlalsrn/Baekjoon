#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char total[500001];
	int N, K, cnt = 0, index = 0;
	string x;
	cin >> N >> K >> x;
	for (int i = 0; i < N; i++)
	{
		if (cnt != K)
		{
			while (index != 0 && total[index-1] < x[i])
			{
				index--;
				cnt++;
				if (cnt == K)
					break;
			}
		}
		total[index++] = x[i];
	}
	while (cnt != K)
	{
		index--;
		cnt++;
	}
	total[index] = '\0';
	cout << total;
	return 0;
}