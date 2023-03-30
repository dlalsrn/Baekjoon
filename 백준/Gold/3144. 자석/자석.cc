#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, mn = 100000000;
vector <int> v;
string x, last = "";

int main(void)
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x == last)
			v.back()++;
		else
		{
			v.push_back(1);
			last = x;
		}
	}

	int i = 0, j = 0, sum = v[0];

	while (1)
	{
		if (sum == L)
		{
			if ((j - i + 1) % 2)
				mn = min(mn, (j - i + 1) / 2);
			else
				if (i == 0 || j == v.size() - 1)
					mn = min(mn, (j - i + 1) / 2);
			sum -= v[i++];
			if (++j == v.size())
				break;
			sum += v[j];
		}
		else if (sum > L)
		{
			sum -= v[i];
			if (i == j)
				j++;
			if (j == v.size())
				break;
			i++;
		}
		else
		{
			if (++j == v.size())
				break;
			sum += v[j];
		}
	}

	cout << mn;

	return 0;
}