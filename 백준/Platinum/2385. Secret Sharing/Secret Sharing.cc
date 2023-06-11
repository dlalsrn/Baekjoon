#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string t, ans = "INVALID";
vector <string> v;

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main(void)
{
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		if (v[i][0] != '0')
		{
			t = v[i];
			for (int j = 0; j < N; j++)
				if (j != i)
					t += v[j];
			ans = min(ans, t);
		}
	}

	cout << ans;

	return 0;
}