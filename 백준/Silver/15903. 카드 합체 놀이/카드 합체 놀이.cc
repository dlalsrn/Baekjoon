#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue <ll, vector<ll>, greater<ll>> pq;
ll N, M, x, sum = 0;

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		pq.push(x);
	}

	for (int i = 0; i < M; i++)
	{
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}