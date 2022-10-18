#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue <ll, vector<ll>, greater<ll>> q;
	ll T, N, num, sum;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		sum = 1;
		q = priority_queue<ll, vector<ll>, greater<ll>>();
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			q.push(num);
		}
		while (q.size() != 1)
		{
			ll a = q.top();
			q.pop();
			ll b = q.top();
			q.pop();
			q.push(a * b);
			sum = sum * ((a * b) % MOD) % MOD;
		}
		cout << sum << '\n';
		
	}
}