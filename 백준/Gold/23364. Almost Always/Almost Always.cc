#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector <int> v;
map <int, int> m;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> N;

	v = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < N; i++)
	{
		if (m.find(v[i]) != m.end())
		{
			cout << i + 1 << ' ' << m[v[i]];
			break;
		}
		m[v[i]] = i + 1;
	}

	return 0;
}