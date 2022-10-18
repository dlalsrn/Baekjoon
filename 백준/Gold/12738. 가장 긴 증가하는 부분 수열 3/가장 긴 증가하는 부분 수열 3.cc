#include <iostream>
#include <vector>
using namespace std;

int find(int n, vector <int> v)
{
	int min = 0, max = v.size() - 1, mid;
	while (max-min > 0)
	{
		mid = (min + max) / 2;
		if (v[mid] >= n)
			max = mid;
		else
			min = mid + 1;
	}
	return min;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> v;
	int N, n, index, min, max, mid;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (i == 0)
			v.push_back(n);
		else
		{
			if (n <= v.back())
			{ 
				min = 0;
				max = v.size();
				while (max - min > 0)
				{
					mid = (min + max) / 2;
					if (v[mid] >= n)
						max = mid;
					else
						min = mid + 1;
				}
				v[min] = n;
			}
			else
				v.push_back(n);
		}
	}

	cout << v.size();
	return 0;
}