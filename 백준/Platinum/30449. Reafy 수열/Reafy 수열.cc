#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, K, cnt = 2;
bool v[5001][5001] = { false };
pi ans[7700000] = { {0, 0} };

bool cmp(pi a, pi b)
{
	return (a.first * b.second) < (a.second * b.first);
}

int main(void)
{
	cin >> N >> K;

	ans[0] = make_pair(0, 1);
	ans[1] = make_pair(1, 2);

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < ((i + 1) >> 1); j++)
		{
			if (!v[j][i])
			{
				ans[cnt++] = make_pair(j, i);
				int a = j + j, b = i + i;
				while (b <= N)
				{
					v[a][b] = true;
					a += j;
					b += i;
				}
			}
		}
	}


	if (K > cnt)
	{
		int index = cnt - (K - cnt) - 1;
		nth_element(ans, ans + index, ans + cnt, cmp);
		int b = ans[index].second;
		int a = b - ans[index].first;
		cout << a << ' ' << b;
	}
	else
	{
		nth_element(ans, ans + K - 1, ans + cnt, cmp);
		cout << ans[K - 1].first << ' ' << ans[K - 1].second;
	}

	return 0;
}