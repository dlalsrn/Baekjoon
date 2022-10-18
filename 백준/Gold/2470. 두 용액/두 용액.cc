#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, num, min_i, min_j, min = 2000000000;
	vector <int> v;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	i = 0;
	min_i = 0;
	j = v.size() - 1;
	min_j = v.size() - 1;

	while (i < j)
	{
		int temp = v[i] + v[j];
		if (min > abs(temp))
		{
			min = abs(temp);
			min_i = i;
			min_j = j;
		}
		if (temp > 0)
			j--;
		else if (temp < 0)
			i++;
		else
		{
			min_i = i;
			min_j = j;
			break;
		}
	}
	cout << v[min_i] << ' ' << v[min_j];
	return 0;
}