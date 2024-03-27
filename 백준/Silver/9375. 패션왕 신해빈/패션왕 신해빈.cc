#include <bits/stdc++.h>
using namespace std;

int T, N, ans = 1;
string name, kind;
map <string, int> m;
vector <string> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		v = vector<string>();
		m = map<string, int>();
		ans = 1;

		for (int i = 0; i < N; i++)
		{
			cin >> name >> kind;
			m[kind]++;
			v.push_back(kind);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		for (int i = 0; i < v.size(); i++) ans *= (m[v[i]] + 1);

		cout << ans - 1 << '\n';
	}

	return 0;
}