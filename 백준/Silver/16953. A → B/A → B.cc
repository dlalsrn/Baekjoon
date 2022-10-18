// A -> B
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
	map <ll, int> m;
	queue <pair<ll, int>> q;
	ll A;
	int B;
	cin >> A >> B;
	q.push({ A, 1 });
	m[A] = 1;
	while (!q.empty())
	{
		pair<ll, int> temp = q.front();
		q.pop();
		ll num = temp.first;
		int cnt = temp.second;
		ll plus_1 = stoll(to_string(num) + "1");
		ll mult_2 = num * 2;
		if (plus_1 <= B)
		{
			if (!m[plus_1])
			{
				m[plus_1] = cnt+1;
				q.push({ plus_1, cnt + 1 });
			}
			else
			{
				if (m[plus_1] > cnt + 1)
				{
					m[plus_1] = cnt + 1;
					q.push({ plus_1, cnt + 1 });
				}
			}
		}
		if (mult_2 <= B)
		{
			if (!m[mult_2])
			{
				m[mult_2] = cnt + 1;
				q.push({ mult_2, cnt + 1 });
			}
			else
			{
				if (m[mult_2] > cnt + 1)
				{
					m[mult_2] = cnt + 1;
					q.push({ mult_2, cnt + 1 });
				}
			}
		}
	}
	if (m[B])
		cout << m[B];
	else
		cout << -1;
	return 0;
}