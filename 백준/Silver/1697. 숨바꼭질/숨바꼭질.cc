// 숨바꼭질
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <bool> check(100001, false);
vector <int> v(100001);
queue <int> q;
int N, K;

int main(void)
{
	cin >> N >> K;
	q.push(N);
	check[N] = true;
	v[N] = 0;

	while (!q.empty())
	{
		int x = q.front(), cnt = v[x];
		q.pop();

		if (x - 1 >= 0)
		{
			if (!check[x - 1] || cnt + 1 < v[x - 1])
			{
				check[x - 1] = true;
				v[x - 1] = cnt + 1;
				q.push(x - 1);
			}
		}
		if (x + 1 <= 100000)
		{
			if (!check[x + 1] || cnt + 1 < v[x + 1])
			{
				check[x + 1] = true;
				v[x + 1] = cnt + 1;
				q.push(x + 1);
			}
		}
		if (x * 2 <= 100000)
		{
			if (!check[x * 2] || cnt + 1 < v[x * 2])
			{
				check[x * 2] = true;
				v[x * 2] = cnt + 1;
				q.push(x * 2);
			}
		}
	}

	cout << v[K];

	return 0;
}