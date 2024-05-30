#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector <ll> v, sum;

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++) cin >> v[i];

	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			sum.push_back(v[i] + v[j]);

	sort(sum.begin(), sum.end());
	sort(v.begin(), v.end());

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			ll t = v[i] - v[j];
			bool exist = binary_search(sum.begin(), sum.end(), t);
			if (exist)
			{
				cout << v[i];
				return 0;
			}
		}
	}

	return 0;
}