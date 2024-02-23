#include <bits/stdc++.h>
using namespace std;

vector <int> v(3);
bool t1 = false, t2 = false;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);
	
	for (int i = 0; i < 3; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	if (v[0] == v[1] && v[1] == v[2]) t1 = true;
	if (v[2] * v[2] == v[0] * v[0] + v[1] * v[1]) t2 = true;
	if (!t1 && !t2) cout << 0;
	if (!t1 && t2) cout << 1;
	if (t1 && !t2) cout << 2;

	return 0;
}