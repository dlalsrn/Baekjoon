#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B, num, cnt;
queue <pair<ll, ll>> q;

int main(void)
{
	cin >> A >> B;

	q.push({ A, 1 });

	while (!q.empty())
	{
		num = q.front().first, cnt = q.front().second;
		q.pop();

		if (num > B) continue;
		else if (num == B)
		{
			cout << cnt;
			return 0;
		}

		ll plus = num * 10 + 1;
		ll mul = num * 2;

		q.push(make_pair(plus, cnt + 1));
		q.push(make_pair(mul, cnt + 1));
	}

	cout << -1;

	return 0;
}