#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int N, T, l, r, ans = 0;
priority_queue <pi, vector<pi>, greater<pi>> q1;
priority_queue <pi, vector<pi>, greater<pi>> q2;

int main(void)
{
	cin >> N >> T;

	for (int i = 0; i < N; i++)
	{
		cin >> l >> r;
		ans = max(ans, l);
		q1.push(make_pair(l, r));
		q2.push(make_pair(r, l));
		T -= l;
	}
	
	if (T < 0)
	{
		cout << -1;
		return 0;
	}

	while (!q1.empty() && T > 0)
	{
		T -= (ans <= q1.top().second ? ans - q1.top().first : q1.top().second - q1.top().first);
		q1.pop();
	}

	if (T <= 0)
		cout << ans;
	else
	{
		while (!q2.empty() && q2.top().first < ans)
			q2.pop();

		while (!q2.empty() && (q2.top().first - ans) * q2.size() <= T)
		{
			T -= (q2.top().first - ans) * q2.size();
			ans += q2.top().first - ans;
			q2.pop();
		}

		if (q2.empty() && T > 0)
			cout << -1;
		else
		{
			if (T == 0)
				cout << ans;
			else if (T % q2.size())
				cout << ans + T / q2.size() + 1;
			else
				cout << ans + T / q2.size();
		}
	}

	return 0;
}