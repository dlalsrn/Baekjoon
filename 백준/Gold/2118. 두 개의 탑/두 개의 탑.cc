#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, mx = 0, l, r;
vector <int> v;
vector <int> L;
vector <int> R;

int main(void)
{
	cin >> N;

	L = vector<int>(N + 1, 0);
	R = vector<int>(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < N; i++)
		R[i + 1] = v[i] + R[i];

	for (int i = 0; i < N; i++)
		L[i + 1] = v[N - 1 - i] + L[i];

	l = 0, r = 1;

	while (1)
	{
		if (mx < max(mx, min(R[r] - R[l], L[N - r] + R[l])) || R[r] - R[l] < L[N - r] + R[l])
		{
			mx = max(mx, min(R[r] - R[l], L[N - r] + R[l]));
			if (++r > N)
				break;
		}
		else
			if (++l > N)
				break;
	}

	cout << mx;

	return 0;
}