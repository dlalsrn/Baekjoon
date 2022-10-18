#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int main(void)
{
	ll N, h, cnt, max;

	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		stack <pair<ll, ll>> s;
		max = 0;
		for (ll i = 0; i < N; i++)
		{
			cin >> h;
			if (s.empty())
				s.push(make_pair(h, 1));
			else
			{
				cnt = 0;
				while (!s.empty() && s.top().first > h)
				{
					cnt += s.top().second;
					if (max < cnt * s.top().first)
						max = cnt * s.top().first;
					s.pop();
				}
				s.push(make_pair(h, cnt + 1));
			}
		}

		cnt = 0;
		while (!s.empty())
		{
			cnt += s.top().second;
			if (max < cnt * s.top().first)
				max = cnt * s.top().first;
			s.pop();
		}
		cout << max << '\n';
	}
	return 0;
}