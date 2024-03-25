#include <bits/stdc++.h>
using namespace std;

string x, t = "";
vector <string> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> x;

	for (int i = x.size() - 1; i >= 0; i--)
	{
		t = x[i] + t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}