#include <bits/stdc++.h>
using namespace std;

int N, sum;
string a;
vector <pair<int, pair<int, string>>> v;

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		sum = 0;

		for (int j = 0; j < a.size(); j++)
		{
			if (0 <= a[j] - 48 && a[j] - 48 <= 9)
				sum += a[j] - 48;
		}
		v.push_back(make_pair(a.size(), make_pair(sum, a)));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		cout << v[i].second.second << '\n';

	return 0;
}