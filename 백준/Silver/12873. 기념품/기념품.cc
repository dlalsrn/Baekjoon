#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, cnt = 1;
queue <int> q;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() != 1)
	{
		ll x = cnt * cnt * cnt;
		x--;
		x %= q.size();
		for (int i = 0; i < x; i++)
		{
			q.push(q.front());
			q.pop();
		}
		q.pop();
		cnt++;
	}

	cout << q.front();

	return 0;
}