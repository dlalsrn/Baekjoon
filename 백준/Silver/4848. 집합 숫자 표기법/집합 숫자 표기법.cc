#include <bits/stdc++.h>
using namespace std;

map <string, int> m1;
map <int, string> m2;
int N;
string x;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	m1["{}"] = 0;
	m2[0] = "{}";
	m1["{{}}"] = 1;
	m2[1] = "{{}}";

	for (int i = 2; i <= 15; i++)
	{
		x = m2[i - 1];
		x.pop_back();
		x += ',' + m2[i - 1] + '}';
		m2[i] = x;
		m1[x] = i;
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string t1, t2;
		cin >> t1 >> t2;
		cout << m2[m1[t1] + m1[t2]] << '\n';
	}

	return 0;
}