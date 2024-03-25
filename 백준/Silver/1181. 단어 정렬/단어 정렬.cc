#include <bits/stdc++.h>
using namespace std;

int N;
string x;
vector <string> v;

bool compare(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++)
	{
		if (i == 0) cout << v[i] << '\n';
		else
		{
			if (v[i] != v[i - 1]) 
				cout << v[i] << '\n';
		}
	}

	return 0;
}