#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;


ll N, M, K;
ll ans = -1;
vector<pi> beer;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i)
	{
		ll v, c;
		cin >> v >> c;

		beer.emplace_back(v, c);
	}

	auto cmp = [](pi a, pi b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	};

	sort(beer.begin(), beer.end(), cmp);

	ll low = 0;
	ll high = (1LL << 32) - 1;
	while (low < high)
	{
		ll mid = (low + high) / 2;

		ll cnt = 0;
		ll sum = 0;
		for (ll i = 0; i < beer.size(); ++i)
		{
			if (beer[i].second <= mid)
			{
				++cnt;
				sum += beer[i].first;
			}

			if (cnt == N) break;
		}

		if (cnt == N && sum >= M)
		{
			ans = mid;
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}