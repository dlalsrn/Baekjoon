#include <bits/stdc++.h>
using namespace std;

int N, M, cnt = -1;
string x;
map <string, bool> m;
vector <string> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N >> M;

	v.resize(M, "");

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		for (int j = 0; j < M; j++) 
			v[j] = x[j] + v[j];
	}

	while (v[0].size())
	{
		m = map<string, bool>();

		for (int i = 0; i < M; i++)
		{
			if (m.find(v[i]) == m.end()) m[v[i]] = true;
			else
			{
				cout << cnt;
				return 0;
			}
		}

		cnt++;

		for (int i = 0; i < M; i++) v[i].pop_back();
	}

	cout << cnt;

	return 0;
}