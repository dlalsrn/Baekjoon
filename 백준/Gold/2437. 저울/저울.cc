#include <bits/stdc++.h>
using namespace std;

int N, s = 1;
vector <int> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (v[i] > s)
			break;
		s += v[i];
	}
	
	cout << s;

	return 0;
}