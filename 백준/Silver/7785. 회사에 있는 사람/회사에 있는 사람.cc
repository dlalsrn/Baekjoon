#include <bits/stdc++.h>
using namespace std;

int N;
string a, b;
map <string, int> m;
vector <string> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (b == "enter") m[a]++;
		else m[a]--;
	}

	for (auto iter = m.begin(); iter != m.end(); iter++)
		if ((*iter).second)
			v.push_back((*iter).first);

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}