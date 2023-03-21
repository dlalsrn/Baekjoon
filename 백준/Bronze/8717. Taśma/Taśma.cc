#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, sum = 0, ans = 1000000001;
vector <int> v;

int main(void)
{
	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	int x = 0;
	for (int i = 0; i < N - 1; i++)
	{
		x += v[i];
		sum -= v[i];
		ans = min(ans, abs(sum - x));
	}

	cout << ans;

	return 0;
}