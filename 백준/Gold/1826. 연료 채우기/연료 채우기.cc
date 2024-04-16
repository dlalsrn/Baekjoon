#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll N, a, b, L, P, cnt = 0;
vector <pi> v;
priority_queue <ll> oil;
stack <pi> st;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), [](pi a, pi b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first; });

	cin >> P >> L;

	for (int i = 0; i < v.size();)
	{
		if (v[i].first <= L)
		{
			oil.push(v[i].second);
			i++;
			continue;
		}

		if (oil.empty()) break;

		cnt++;
		L += oil.top();
		if (P <= L) break;
		oil.pop();
	}

	while (!oil.empty())
	{
		if (P <= L) break;
		cnt++;
		L += oil.top();
		oil.pop();
	}

	cout << (P <= L ? cnt : -1);

	return 0;
}