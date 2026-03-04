#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll N, K;
vector<ll> v;
vector<pl> course;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		ll x;
		cin >> x;
		v.push_back(x);
	}

	ll cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cnt += v[i];
		course.emplace_back(cnt, i + 1);
	}

	for (int i = N - 1; i >= 0; --i)
	{
		cnt += v[i];
		course.emplace_back(cnt, i + 1);
	}

	for (int i = 0; i < course.size(); ++i)
	{
		if (K < course[i].first)
		{
			cout << course[i].second << '\n';
			break;
		}
	}

	return 0;
}