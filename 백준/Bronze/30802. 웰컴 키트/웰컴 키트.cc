#include <bits/stdc++.h>
using namespace std;

int N, T, P;
int cnt = 0;
vector <int> v(6);

int main(void)
{
	cin.tie(0)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < 6; i++) {
		cin >> v[i];
	}

	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		if (v[i] == 0) continue;
		cnt += (v[i] - 1) / T + 1;
	}

	cout << cnt << '\n';
	cout << N / P << ' ' << N % P;

	return 0;
}