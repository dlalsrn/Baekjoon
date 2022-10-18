#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	vector <ll> v;
	int N, num;
	ll cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		int j = 0;
		int k = N - 1;;
		while (j < k)
		{
			if (j == i)
				j++;
			if (k == i)
				k--;
			if (j == k)
				break;
			if (v[j] + v[k] > v[i])
				k--;
			else if (v[j] + v[k] < v[i])
				j++;
			else
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}