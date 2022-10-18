#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	long long N, B, C, sum = 0, mn;
	cin >> N >> B >> C;
	vector <long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	if (B <= C)
	{
		for (int i = 0; i < N; i++)
			sum += B * v[i];
		cout << sum;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		if (!v[i])
			continue;
		if (i < N - 2 && v[i] && v[i + 1] && v[i + 2])
		{
			mn = min(v[i], min(v[i + 1], v[i + 2]));
			if (v[i + 1] > v[i + 2])
			{
				mn = min(v[i + 1] - v[i + 2], v[i]);
				sum += (B + C) * mn;
				v[i] -= mn;
				v[i + 1] -= mn;
				i--;
				continue;
			}
			else
			{
				v[i] -= mn;
				v[i + 1] -= mn;
				v[i + 2] -= mn;
				sum += (B + 2 * C) * mn;
			}
		}
		if (i < N - 1 && v[i] && v[i + 1])
		{
			mn = min(v[i], v[i + 1]);
			sum += (B + C) * mn;
			v[i] -= mn;
			v[i + 1] -= mn;
		}
		if (v[i])
		{
			sum += B * v[i];
			v[i] = 0;
		}
	}
	cout << sum;
}