// 용액 합성하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, num, min = 200000001, sum;
	vector <int> v;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	i = 0;
	j = N - 1;

	while (i < j)
	{
		int temp = v[i] + v[j];
		if (min > abs(temp))
		{
			min = abs(temp);
			sum = temp;
			if (min == 0)
				break;
		}
		if (temp > 0)
			j--;
		else if (temp < 0)
			i++;
	}
	cout << sum;
	return 0;
}