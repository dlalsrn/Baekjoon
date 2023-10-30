#include <bits/stdc++.h>
using namespace std;

int N, x;
int v[2250000];

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N * N; i++)
		cin >> v[i];

	sort(v, v + N*N);

	cout << v[N*N-N];

	return 0;
}