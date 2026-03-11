#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q, T, P;
int L, R;
vector<int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		v.emplace_back(x);
	}

	sort(v.begin(), v.end());

	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> T >> P;

		int cnt = 0;
		auto it = lower_bound(v.begin(), v.end(), P);

		if (it == v.begin())
		{
			L = P - T;
			R = min(P + T, v[0] - 1);
		}
		else if (it == v.end())
		{
			L = max(P - T, v.back() + 1);
			R = P + T;
		}
		else
		{
			L = max(P - T, *(it - 1) + 1);
			R = min(P + T, *it - 1);
		}

		long long ans = 0;

		if (L <= R)
		{
			long long first = L;
			if ((first - (P + T)) % 2 != 0) first++;

			if (first <= R) ans = (R - first) / 2 + 1;
		}

		cout << ans << '\n';
	}

	return 0;
}