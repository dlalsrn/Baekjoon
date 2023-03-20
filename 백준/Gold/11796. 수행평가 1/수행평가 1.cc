#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll N, M;
vector <ll> v;
set <deque<ll>> s;
deque <ll> dq;

int main(void)
{
	cin >> N >> M;

	v = vector<ll>(N);

	for (ll i = 0; i < N; i++)
		cin >> v[i];

	for (ll sz = 1; sz <= N; sz++)
	{
		dq = deque<ll>();
		s = set <deque<ll>>();

		for (ll i = 0; i < N; i++)
		{
			dq.push_back(v[i]);
			if (dq.size() == sz)
			{
				s.insert(dq);
				dq.pop_front();
			}
		}

		ll all = pow(M, sz);
		all %= MOD;
		
		if (M == 1)
		{
			cout << N+1 << ' ' << 1;
			return 0;
		}
		if (s.size() != all)
		{
			if (all - s.size() < 0)
				cout << sz << ' ' << all - s.size() + MOD;
			else
				cout << sz << ' ' << all - s.size();
			return 0;
		}
	}
}
