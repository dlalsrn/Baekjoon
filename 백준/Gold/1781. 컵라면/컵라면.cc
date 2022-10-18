#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

struct compare
{
	bool operator()(pair<ll, ll> a, pair<ll, ll> b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first > b.first;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, compare> q;
	priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> s;
	pair<ll, ll> temp;
	ll N, sum = 0, deadline = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp.first >> temp.second;
		q.push(temp);
	}

	for (int i = 0; i < N; i++)
	{
		temp = q.top();
		q.pop();
		if (i == 0)
		{
			s.push({temp.second, temp.first});
			sum += temp.second;
			deadline++;
		}
		else
		{
			if (deadline < temp.first)
			{
				sum += temp.second;
				s.push({ temp.second, temp.first });
				deadline++;
			}
			else
			{
				if (s.top().first < temp.second)
				{
					sum -= s.top().first;
					s.pop();
					sum += temp.second;
					s.push({ temp.second, temp.first });
				}
			}

		}
	}
	cout << sum;
	return 0;
}