// A -> B
#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

ll A, B;
queue <pair<ll, int>> q;

int main(void)
{
	cin >> A >> B;

	q.push({ A, 1 });
	
	while (!q.empty())
	{
		ll num = q.front().first, cnt = q.front().second;
		q.pop();
		if (num > B)
			continue;
		ll plus = stoll(to_string(num) + "1");
		ll mult = num * 2;

		if (num == B)
		{
			cout << cnt;
			return 0;
		}
		if (plus <= B)
			q.push(make_pair(plus, cnt + 1));
		if (mult <= B)
			q.push(make_pair(mult, cnt + 1));
	}

	cout << -1;

	return 0;
}