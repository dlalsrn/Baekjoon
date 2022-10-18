#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, S, sum = 0, left, right, min = 100001;
	cin >> N >> S;
	vector <ll> v(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	left = 0;
	right = 0;

	while (right <= N)
	{
		if (sum < S)
		{
			if (right == N)
				break;
			sum += v[right++];
		}
		else
		{
			if (right - left < min)
			{
				min = right - left;
				if (min == 1)
					break;
			}
			sum -= v[left++];
		}
		//cout << sum << ' ' << left << ' ' << right << '\n';
	}
	if (min == 100001)
		cout << 0;
	else
		cout << min;

	return 0;
}