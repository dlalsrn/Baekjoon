#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, num, sum = 0, cnt = 0;
	vector <int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		sum ^= num;
	}
	if (sum)
	{
		for (int i = 0; i < N; i++)
		{
			if ((sum^v[i]) < v[i])
				cnt++;
		}
		cout << cnt;
	}
	else
		cout << 0;
	return 0;
}