#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int N, x, ans = 0;
vector <pi> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(make_pair(x, i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		ans = max(ans, v[i].second - i);

	cout << ans;

	return 0;
}