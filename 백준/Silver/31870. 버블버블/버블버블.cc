#include <bits/stdc++.h>
using namespace std;

int N, asc_cnt = 0, desc_cnt = 0, x;
vector <int> asc, desc;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		asc.push_back(x);
		desc.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (asc[j] > asc[j + 1])
			{
				swap(asc[j], asc[j + 1]);
				asc_cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (desc[j] < desc[j + 1])
			{
				swap(desc[j], desc[j + 1]);
				desc_cnt++;
			}
		}
	}
	
	cout << min(asc_cnt, desc_cnt + 1);

	return 0;
}