// 숨바꼭질 2
// 23.04.10
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <bool> check(100001, false);
vector <pair<int, int>> v(100001, { 0, 0 });
queue <int> q;
int N, K;

int main(void)
{
	cin >> N >> K;
	q.push(N);
	check[N] = true;
	v[N] = { 0, 1 };

	while (!q.empty())
	{
		int x = q.front();
		int cnt = v[x].first;
		q.pop();

		if (x - 1 >= 0)
		{
			if (!check[x - 1] || cnt + 1 < v[x - 1].first)
			{
				check[x - 1] = true;
				v[x - 1].first = cnt + 1;
				v[x - 1].second = 1;
				q.push(x - 1);
			}
			else if (cnt + 1 == v[x - 1].first)
			{
				v[x - 1].second++;
				q.push(x - 1);
			}
		}
		if (x + 1 <= 100000)
		{
			if (!check[x + 1] || cnt + 1 < v[x + 1].first)
			{
				check[x + 1] = true;
				v[x + 1].first = cnt + 1;
				v[x + 1].second = 1;
				q.push(x + 1);
			}
			else if (cnt + 1 == v[x + 1].first)
			{
				v[x + 1].second++;
				q.push(x + 1);
			}
		}
		if (x * 2 <= 100000)
		{
			if (!check[x * 2] || cnt + 1 < v[x * 2].first)
			{
				check[x * 2] = true;
				v[x * 2].first = cnt + 1;
				v[x * 2].second = 1;
				q.push(x * 2);
			}
			else if (cnt + 1 == v[x * 2].first)
			{
				v[x * 2].second++;
				q.push(x * 2);
			}
		}
	}

	cout << v[K].first << '\n' << v[K].second;

	return 0;
}