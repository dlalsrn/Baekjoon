#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, K, num, cnt, mx;
	map <ll, bool> m;
	vector <ll> v;
	priority_queue <ll, vector<ll>, greater<ll>> q;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> num;
		v.push_back(num);
		q.push(num);
		m[num] = true;
		mx = max(mx, num);
	}
	cnt = N;
	while (cnt != 1)
	{
		ll n = q.top();
		q.pop();
		for (int i = 0; i < K; i++)
		{
			ll t = n * v[i];
			if (q.size() >= N && t > mx)
				break;
			if (!m[t])
			{
				q.push(t);
				m[t] = true;
				mx = max(mx, t);
			}
		}
		cnt--;
	}
	cout << q.top();
	return 0;
}