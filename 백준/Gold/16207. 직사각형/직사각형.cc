#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack <ll> s;
	priority_queue <ll> q;
	ll N, dis, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> dis;
		q.push(dis);
	}

	for (int i = 0; i < N; i++)
	{
		if (q.empty())
			break;
		ll t = q.top();
		q.pop();
		if (q.empty())
			break;
		if (t == q.top())
		{
			s.push(t);
			q.pop();
		}
		else if (t - 1 == q.top())
		{
			s.push(t - 1);
			q.pop();
		}
	}
	if (s.size() % 2 == 1)
		s.pop();
	while (!s.empty())
	{
		ll a = s.top();
		s.pop();
		ll b = s.top();
		s.pop();
		sum += a * b;
	}
	cout << sum;
	return 0;
}