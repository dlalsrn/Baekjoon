#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
int main(void)
{
	ll N, n, cnt = 0, max = -1, max_l, max_r, l, r;
	stack <pair<ll, pair<ll, ll>>> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (s.empty())
			s.push(make_pair(n, make_pair(0, i + 1)));
		else
		{
			cnt = 0;
			r = i;
			l = i + 1;
			while (!s.empty() && s.top().first > n)
			{
				cnt += s.top().first + s.top().second.first;
				l = s.top().second.second;
				if (s.top().first * cnt > max)
				{
					max_r = r;
					max_l = l;
					max = s.top().first * cnt;
				}
				s.pop();
			}
			s.push(make_pair(n, make_pair(cnt, l)));
		}
	}
	cnt = 0;
	r = s.top().second.second;
	l = s.top().second.second;
	while (!s.empty())
	{
		cnt += s.top().first + s.top().second.first;
		l = s.top().second.second;
		if (s.top().first * cnt > max)
		{
			max_r = r;
			max = s.top().first * cnt;
			max_l = l;
		}
		s.pop();
	}
	cout << max << '\n';
	cout << max_l << ' ' << max_r;
	return 0;
}