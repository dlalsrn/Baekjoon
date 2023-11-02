#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, N;
vector <ll> v;
vector <ll> ans;
map <ll, int> m;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		v = vector<ll>(N * 2);
		ans = vector<ll>();
		m = map<ll, int>();
		x = "";

		for (int i = 0; i < N * 2; i++)
		{
			cin >> v[i];
			m[v[i]]++;
		}

		for (int i = N * 2 - 1; i >= 0; i--)
		{
			if (!m[v[i]])
				continue;
			ans.push_back(v[i] / 4 * 3);
			m[v[i]]--;
			m[v[i] / 4 * 3]--;
		}

		cout << "Case #" << t + 1 << ": ";
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << ' ';

		cout << '\n';
	}

	return 0;
}