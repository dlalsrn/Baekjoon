#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

priority_queue <ll, vector<ll>, greater<ll>> pq;
ll x;
int N, M;

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

		x = a + b;
		a = b = x;

		pq.push(a);
		pq.push(b);
	}

	x = 0;

	while (!pq.empty())
	{
		x += pq.top();
		pq.pop();
	}

	cout << x;

	return 0;
}