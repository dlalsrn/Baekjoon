#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, money, c, num, cnt = 0, sale;
vector <int> v;
vector<int> dp[100001];
int arr[100001];

int main(void)
{
	cin >> N >> money >> c;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (v[i] <= money)
		{
			cnt++;
			money -= v[i];
		}
		else
		{
			sale = i - 1;
			while (c > 0 && i < N)
			{
				if (v[i] / 2 <= money)
				{
					money -= v[i] / 2;
					cnt++;
					i++;
					c--;
					continue;
				}
				if (sale < 0)
					break;
				money += v[sale] / 2;
				sale--;
				c--;
			}
			break;
		}
	}
	cout << cnt;
}