#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<ll, ll>> q;
	vector <ll> v(10001, 0);
	ll N, p, d, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		q.push({ p, d });
	}

	for (int i = 0; i < N; i++)
	{
		pair<ll, ll> temp = q.top();
		q.pop();
		if (v[temp.second] == 0)
		{
			v[temp.second] = temp.first;
			sum += temp.first;
		}
		else
		{
			while (temp.second != 0 && v[temp.second])
				temp.second--;
			if (temp.second != 0)
			{
				v[temp.second] = temp.first;
				sum += temp.first;
			}
		}
	}
	cout << sum;
	return 0;
}