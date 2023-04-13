#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, mx = 0, ans = 0;
vector <int> v;
vector <int> L; // 왼쪽으로 돌 때
vector <int> R; // 오른쪽으로 돌 때

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
	{
		R[i + 1] = v[i];
		if (i)
			R[i + 1] += R[i];
	}

	for (int i = 0; i < N; i++)
	{
		L[i + 1] = v[N - 1 - i];
		if (i)
			L[i + 1] += L[i];
	}

	int i = 0, j = 1;

	while (1)
	{
		if (mx < max(mx, min(R[j] - R[i], L[N - j] + R[i])) || R[j] - R[i] < L[N - j] + R[i])
		{
			mx = max(mx, min(R[j] - R[i], L[N - j] + R[i]));
			if (++j > N)
				break;
		}
		else
		{
			if (++i > N)
				break;
		}
	}

	cout << mx;

	return 0;
}