#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a, b, c, d;
bool TF;
vector <int> v, t;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	cin >> a >> b >> c >> d;

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);

	TF = true;
	for (int i = 0; i < 3; i++)
		if (v[i] >= v[i + 1])
			TF = false;

	if (TF)
	{
		cout << "Fish Rising";
		return 0;
	}

	TF = true;
	for (int i = 0; i < 3; i++)
		if (v[i] <= v[i + 1])
			TF = false;

	if (TF)
	{
		cout << "Fish Diving";
		return 0;
	}

	TF = true;
	for (int i = 0; i < 3; i++)
		if (v[i] != v[i + 1])
			TF = false;

	if (TF)
	{
		cout << "Fish At Constant Depth";
		return 0;
	}

	cout << "No Fish";

	return 0;
}