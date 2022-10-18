#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <pair<ll, ll>> q;
	multiset <ll> s;
	pair<ll, ll> temp;
	ll N, K, C, sum = 0, cnt = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> temp.second >> temp.first;
		q.push(temp);
	}
		
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		s.insert(C);
	}
	for (int i = 0; i < N; i++)
	{
		if (cnt == K)
			break;
		if (q.top().second > *s.rbegin())
			q.pop();
		else
		{
			sum += q.top().first;
			s.erase(s.lower_bound(q.top().second));
			q.pop();
			cnt++;
		}
	}
	cout << sum;
	return 0;
}